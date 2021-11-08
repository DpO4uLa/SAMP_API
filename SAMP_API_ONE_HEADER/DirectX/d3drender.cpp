////////////////////////////////////////////////////////////////////////
// This font class was created by Azorbix (Matthew L) for Game-Deception
// http://www.game-deception.com   http://forum.game-deception.com
// irc://irc.rizon.net/game-deception
//
// A lot all of the CD3DFont::Initialize() code was created by Microsoft
// (taken from the D3D9 SDK)
//
// Please note that this is NOT 100% complete yet, colour tags and
// shadows are not implemented yet
//
// USAGE:
//   CD3DFont:
//     1) Instanciate the class with the parameterized constructor
//        eg CD3DFont *g_pD3Dfont = new CD3DFont("Arial", 16, FCT_BOLD);
//
//     2) Call Initialize() after other rendering is ready
//        eg g_pD3DFont->Initialize(pD3Ddevice);
//
//     3) To begin rendering use Print function
//        eg g_pD3DFont->Print(10.0f, 50.0f, 0xFF00FF00, "Hello World", FT_BORDER);
//
//     4) call Invalidate() upon Reset of the D3D surface and re-initialize
//
//   CD3DRender:
//     1) Instanciate the class with the parameterized constructor
//        eg CD3DRender *g_pRender = new CD3DRender(128);
//
//     2) Call Initialize() after other rendering is ready
//        eg g_pRender->Initialize(pD3Ddevice);
//
//     3) To begin rendering, start rendering much like OpenGL
//        eg if( SUCCEEDED(g_pRender->Begin(D3DPT_TRIANGLELIST)) )
//           {
//               D3DAddQuad(g_pRender, 10.0f, 10.0f, 50.0f, 50.0f, 0xFFFF0000); //helper function
//               g_pRender->D3DColour(0xFF0000FF); //blue
//               g_pRender->D3DVertex2f(60.0f, 60.0f);
//               g_pRender->D3DVertex2f(60.0f, 110.0f);
//               g_pRender->D3DVertex2f(110.0f, 110.0f);
//               g_pRender->End();
//           }
//
//     4) call Invalidate() upon Reset of the D3D surface and re-initialize
//
// FASTER RENDERING (Advanced but NOT REQUIRED):
//   To enable faster rendering, it's ideal to call static function CD3DBaseRendering::BeginRender(); before
//   other font / primitive rendering code, and call CD3DBaseRendering::EndRender(); afterwards
//   *** IT IS CRUCIAL THAT YOU CALL EndRender FOR EVERY BeginRender() CALL ***
//   *** IMAGE RENDERING MAY BECOME CORRUPT IF YOU DO NOT ***
//   eg
//     if( SUCCEEDED(CD3DBaseRender::BeginRender()) )
//     {
//         //primitive and font rendering goes here
//         CD3DBaseRender::EndRender();
//     }
//#include "main.h"
#include "d3drender.h"

IDirect3DDevice9 *CD3DBaseRender::m_pD3Ddev = NULL;
IDirect3DStateBlock9 *CD3DBaseRender::m_pD3DstateDraw = NULL;
IDirect3DStateBlock9 *CD3DBaseRender::m_pD3DstateNorm = NULL;
int CD3DBaseRender::m_renderCount = 0;
int CD3DBaseRender::m_numShared = 0;
bool CD3DBaseRender::m_statesOK = false;

inline d3dvertex_s Init2DVertex(float x, float y, DWORD color, float tu, float tv)
{
	d3dvertex_s v = { x, y, 1.0f, 1.0f, color, tu, tv };
	return v;
}

CD3DBaseRender::CD3DBaseRender()
{
	m_numShared++;
}

CD3DBaseRender::~CD3DBaseRender()
{
	if (--m_numShared == 0)
		DeleteStates();
}

HRESULT CD3DBaseRender::Initialize(IDirect3DDevice9 *pD3Ddev)
{
	if (m_pD3Ddev == NULL && (m_pD3Ddev = pD3Ddev) == NULL)
		return E_FAIL;

	if (!m_statesOK && FAILED(CreateStates()))
		return E_FAIL;

	return S_OK;
}

HRESULT CD3DBaseRender::Invalidate()
{
	DeleteStates();
	return S_OK;
}

HRESULT CD3DBaseRender::BeginRender()
{
	if (!m_statesOK)
		return E_FAIL;

	if (++m_renderCount == 1)
	{
		m_pD3DstateNorm->Capture();
		m_pD3DstateDraw->Apply();
	}

	return S_OK;
}

HRESULT CD3DBaseRender::EndRender()
{
	if (!m_statesOK)
		return E_FAIL;

	m_renderCount--;

	if (m_renderCount == 0)
		m_pD3DstateNorm->Apply();
	else if (m_renderCount < 0)
		m_renderCount = 0;

	return S_OK;
}

HRESULT CD3DBaseRender::CreateStates()
{
	for (int iStateBlock = 0; iStateBlock < 2; iStateBlock++)
	{
		m_pD3Ddev->BeginStateBlock();
		m_pD3Ddev->SetPixelShader(NULL);
		m_pD3Ddev->SetVertexShader(NULL);

		m_pD3Ddev->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);
		m_pD3Ddev->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
		m_pD3Ddev->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
		m_pD3Ddev->SetRenderState(D3DRS_ALPHATESTENABLE, TRUE);
		m_pD3Ddev->SetRenderState(D3DRS_ALPHAREF, 0x08);
		m_pD3Ddev->SetRenderState(D3DRS_ALPHAFUNC, D3DCMP_GREATEREQUAL);
		m_pD3Ddev->SetRenderState(D3DRS_FILLMODE, D3DFILL_SOLID);
		m_pD3Ddev->SetRenderState(D3DRS_CULLMODE, D3DCULL_CCW);
		m_pD3Ddev->SetRenderState(D3DRS_STENCILENABLE, FALSE);
		m_pD3Ddev->SetRenderState(D3DRS_CLIPPING, TRUE);
		m_pD3Ddev->SetRenderState(D3DRS_CLIPPLANEENABLE, FALSE);
		m_pD3Ddev->SetRenderState(D3DRS_VERTEXBLEND, D3DVBF_DISABLE);
		m_pD3Ddev->SetRenderState(D3DRS_INDEXEDVERTEXBLENDENABLE, FALSE);
		m_pD3Ddev->SetRenderState(D3DRS_FOGENABLE, FALSE);
		m_pD3Ddev->SetRenderState(D3DRS_MULTISAMPLEANTIALIAS, FALSE);
		m_pD3Ddev->SetRenderState(D3DRS_COLORWRITEENABLE, D3DCOLORWRITEENABLE_RED | D3DCOLORWRITEENABLE_GREEN |
			D3DCOLORWRITEENABLE_BLUE | D3DCOLORWRITEENABLE_ALPHA);

		m_pD3Ddev->SetTextureStageState(0, D3DTSS_COLOROP, D3DTOP_MODULATE);
		m_pD3Ddev->SetTextureStageState(0, D3DTSS_COLORARG1, D3DTA_TEXTURE);
		m_pD3Ddev->SetTextureStageState(0, D3DTSS_COLORARG2, D3DTA_DIFFUSE);
		m_pD3Ddev->SetTextureStageState(0, D3DTSS_ALPHAOP, D3DTOP_MODULATE);
		m_pD3Ddev->SetTextureStageState(0, D3DTSS_ALPHAARG1, D3DTA_TEXTURE);
		m_pD3Ddev->SetTextureStageState(0, D3DTSS_ALPHAARG2, D3DTA_DIFFUSE);
		m_pD3Ddev->SetTextureStageState(0, D3DTSS_TEXCOORDINDEX, 0);
		m_pD3Ddev->SetTextureStageState(0, D3DTSS_TEXTURETRANSFORMFLAGS, D3DTTFF_DISABLE);
		m_pD3Ddev->SetTextureStageState(1, D3DTSS_COLOROP, D3DTOP_DISABLE);
		m_pD3Ddev->SetTextureStageState(1, D3DTSS_ALPHAOP, D3DTOP_DISABLE);

		m_pD3Ddev->SetSamplerState(0, D3DSAMP_MINFILTER, D3DTEXF_POINT);
		m_pD3Ddev->SetSamplerState(0, D3DSAMP_MAGFILTER, D3DTEXF_POINT);
		m_pD3Ddev->SetSamplerState(0, D3DSAMP_MIPFILTER, D3DTEXF_NONE);

		if (iStateBlock)
			m_pD3Ddev->EndStateBlock(&m_pD3DstateDraw);
		else
			m_pD3Ddev->EndStateBlock(&m_pD3DstateNorm);
	}

	m_statesOK = true;

	return S_OK;
}

HRESULT CD3DBaseRender::DeleteStates()
{
	SAFE_RELEASE(m_pD3DstateDraw);
	SAFE_RELEASE(m_pD3DstateNorm);
	m_statesOK = false;

	return S_OK;
}

size_t strlcpy(char *dst, const char *src, size_t size)
{
	size_t	len = strlen(src);

	if (size == 0)
		return len;

	if (len >= size)
	{
		size--;
		memcpy(dst, src, size);
		dst[size] = 0;
	}
	else if (size > 0)
	{
		strcpy(dst, src);
	}

	return len;
}

CD3DFont::CD3DFont(const char *szFontName, int fontHeight, DWORD dwCreateFlags)
{
	strlcpy(m_szFontName, (szFontName ? szFontName : "Arial"), sizeof(m_szFontName));

	m_fontHeight = fontHeight;
	m_dwCreateFlags = dwCreateFlags;

	m_isReady = false;
	m_statesOK = false;

	m_pD3Dtex = NULL;
	m_pD3Dbuf = NULL;
	m_pRender = NULL;

	m_maxTriangles = 224 * 4;

	m_texWidth = m_texHeight = 0;
	m_chrSpacing = 0;

	memset(m_fTexCoords, 0, sizeof(float) * 224 * 4);

	m_fChrHeight = 0.0;
}

CD3DFont::~CD3DFont()
{
	Invalidate();
}

/* god, what a mess */
HRESULT CD3DFont::Initialize(IDirect3DDevice9 *pD3Ddev)
{
	if (FAILED(CD3DBaseRender::Initialize(pD3Ddev)))
		return E_FAIL;

	if (m_pRender == NULL && (m_pRender = new CD3DRender(16)) == NULL)
		return E_FAIL;

	if (FAILED(m_pRender->Initialize(pD3Ddev)))
		return E_FAIL;

	m_texWidth = m_texHeight = 1024;

	if (FAILED(m_pD3Ddev->CreateTexture(m_texWidth, m_texHeight, 1, 0, D3DFMT_A4R4G4B4, D3DPOOL_MANAGED, &m_pD3Dtex,
		NULL)))
		return E_FAIL;

	if (FAILED(m_pD3Ddev->CreateVertexBuffer(m_maxTriangles * 3 * sizeof(d3dvertex_s),
		D3DUSAGE_WRITEONLY | D3DUSAGE_DYNAMIC, 0, D3DPOOL_DEFAULT, &m_pD3Dbuf, NULL)))
	{
		SAFE_RELEASE(m_pD3Dtex);
		return E_FAIL;
	}

	DWORD		*pBitmapBits;
	BITMAPINFO	bmi;

	memset(&bmi.bmiHeader, 0, sizeof(BITMAPINFOHEADER));
	bmi.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
	bmi.bmiHeader.biWidth = m_texWidth;
	bmi.bmiHeader.biHeight = -m_texHeight;
	bmi.bmiHeader.biPlanes = 1;
	bmi.bmiHeader.biCompression = BI_RGB;
	bmi.bmiHeader.biBitCount = 32;

	HDC		hDC = CreateCompatibleDC(NULL);
	HBITMAP hbmBitmap = CreateDIBSection(hDC, &bmi, DIB_RGB_COLORS, (void **)&pBitmapBits, NULL, 0);
	SetMapMode(hDC, MM_TEXT);

	int		iHeight = -m_fontHeight * (int)GetDeviceCaps(hDC, LOGPIXELSY) / 72;

	HFONT	hFont = CreateFont(iHeight, 0, 0, 0, (m_dwCreateFlags & FCR_BOLD) ? FW_BOLD : FW_NORMAL,
		m_dwCreateFlags & FCR_ITALICS, false, false, DEFAULT_CHARSET, OUT_TT_PRECIS,
		CLIP_DEFAULT_PRECIS, PROOF_QUALITY, VARIABLE_PITCH, m_szFontName);

	if (hFont == NULL)
	{
		DeleteObject(hbmBitmap);
		DeleteDC(hDC);
		DeleteObject(hFont);
		SAFE_RELEASE(m_pD3Dtex);
		return E_FAIL;
	}

	SelectObject(hDC, hbmBitmap);
	SelectObject(hDC, hFont);

	RECT	all = { 0, 0, m_texWidth - 1, m_texWidth - 1 };
	HBRUSH	green = CreateSolidBrush(RGB(0, 255, 0));
	FillRect(hDC, &all, green);
	DeleteObject(green);

	SetBkMode(hDC, TRANSPARENT);
	SetTextAlign(hDC, TA_TOP);

	SIZE	size;
	char	ch = ' ';

	GetTextExtentPoint32(hDC, &ch, 1, &size);

	m_chrSpacing = (size.cx + 3) / 4;
	m_fChrHeight = (float)(size.cy);

	if (m_dwCreateFlags & FCR_BORDER)
	{
		size.cx += 2;
		size.cy += 2;
	}

	int y = 0, x = (size.cx + 3) / 4;

	for (int c = 32; c < 256; c++)
	{
		ch = (char)c;

		GetTextExtentPoint32(hDC, &ch, 1, &size);
		if (m_dwCreateFlags & FCR_BORDER)
		{
			size.cx += 3;
			size.cy += 3;
		}

		if (x + size.cx + m_chrSpacing > m_texWidth)
		{
			x = m_chrSpacing;
			if (y + size.cy * 2 + 2 < m_texHeight)
				y += size.cy + 1;
		}

		RECT	rect = { x, y, x + size.cx, y + size.cy };

		if (m_dwCreateFlags & FCR_BORDER)
		{
			// XXX retarded :p use font outline instead
			SetTextColor(hDC, RGB(0, 0, 0));
			x++;
			y++;
			ExtTextOut(hDC, x - 1, y - 1, ETO_CLIPPED, &rect, &ch, 1, NULL);
			ExtTextOut(hDC, x, y - 1, ETO_CLIPPED, &rect, &ch, 1, NULL);
			ExtTextOut(hDC, x + 1, y - 1, ETO_CLIPPED, &rect, &ch, 1, NULL);
			ExtTextOut(hDC, x + 1, y, ETO_CLIPPED, &rect, &ch, 1, NULL);
			ExtTextOut(hDC, x + 1, y + 1, ETO_CLIPPED, &rect, &ch, 1, NULL);
			ExtTextOut(hDC, x, y + 1, ETO_CLIPPED, &rect, &ch, 1, NULL);
			ExtTextOut(hDC, x - 1, y + 1, ETO_CLIPPED, &rect, &ch, 1, NULL);
			ExtTextOut(hDC, x - 1, y, ETO_CLIPPED, &rect, &ch, 1, NULL);
			SetTextColor(hDC, RGB(255, 0, 0));
			ExtTextOut(hDC, x, y, ETO_CLIPPED, &rect, &ch, 1, NULL);
			x--;
			y--;
		}
		else
		{
			SetTextColor(hDC, RGB(255, 0, 0));
			ExtTextOut(hDC, x, y, ETO_CLIPPED, &rect, &ch, 1, NULL);
		}

		//tu src + dst
		m_fTexCoords[c - 32][0] = (float)(x + 0 - m_chrSpacing) / (float)m_texWidth;
		m_fTexCoords[c - 32][2] = (float)(x + size.cx + m_chrSpacing) / (float)m_texWidth;

		//tv src + dst
		m_fTexCoords[c - 32][1] = (float)(y + 0 + 0) / (float)m_texHeight;
		m_fTexCoords[c - 32][3] = (float)(y + size.cy + 0) / (float)m_texHeight;

		x += size.cx + (2 * m_chrSpacing);
	}

	D3DLOCKED_RECT	d3dlr;
	m_pD3Dtex->LockRect(0, &d3dlr, 0, 0);

	BYTE	*pDstRow = (BYTE *)d3dlr.pBits;
	WORD	*pDst16;

	for (y = 0; y < m_texHeight; y++)
	{
		pDst16 = (WORD *)pDstRow;

		for (x = 0; x < m_texWidth; x++)
		{
			DWORD	pixel = pBitmapBits[m_texWidth * y + x];
			BYTE	bAlpha = 15 - (((BYTE)(pixel >> 8)) >> 4);	// green channel
			BYTE	bValue = ((BYTE)(pixel >> 16)) >> 4;			// red channel
			*pDst16 = (WORD)(bAlpha << 12) | (bValue << 8) | (bValue << 4) | (bValue);
			pDst16++;
		}

		pDstRow += d3dlr.Pitch;
	}

	m_pD3Dtex->UnlockRect(0);

	DeleteObject(hbmBitmap);
	DeleteDC(hDC);
	DeleteObject(hFont);

	m_isReady = true;

	return S_OK;
}

HRESULT CD3DFont::Invalidate()
{
	m_isReady = false;

	SAFE_RELEASE(m_pD3Dtex);
	SAFE_RELEASE(m_pD3Dbuf);

	//SAFE_RELEASE(m_pD3DstateDraw);
	//SAFE_RELEASE(m_pD3DstateNorm);
	m_pRender->Invalidate();

	return S_OK;
}
/*
static signed char hex_to_dec(signed char ch)
{
	if (ch >= '0' && ch <= '9')
		return ch - '0';
	if (ch >= 'A' && ch <= 'F')
		return ch - 'A' + 10;
	if (ch >= 'a' && ch <= 'f')
		return ch - 'A' + 10;

	return -1;
}

bool hex_is_valid(const std::string& hex)
{
	if (hex.empty())
		return false;
	for (size_t i = 0, len = hex.length(); i < len; i++)
	{
		if (hex_to_dec(hex[i]) == -1)
			return false;
	}
	return true;
}

struct stColorTag
{
	D3DCOLOR _color;
	bool _alpha;
	bool _valid;
};

stColorTag GetColorTag( const char *text, size_t maxLen )
{
	stColorTag color = { 0, false, false };
	const int minLen = 8; // { + XXXXXX + } = 8

	if ( text == nullptr || *text != '{' || maxLen < minLen )
		return color;

	if ( text[7] == '}' )
	{
		color._alpha = false;
		color._valid = true;
	}
	else if ( minLen + 2 <= maxLen && text[9] == '}' )
	{
		color._alpha = true;
		color._valid = true;
	}
	if ( color._valid )
	{
		if ( hex_is_valid( std::string( text ).substr( 1, color._alpha ? 8 : 6 ) ) )
			color._color = strtol( &text[1], nullptr, 16 );
		else
			color._valid = false;
	}
	return color;
}
*/
HRESULT CD3DFont::Print(const char *text, D3DCOLOR color, float x, float y/*, bool skipColorTags, bool noColorFormat*/)
{
	if (!m_isReady || text == nullptr || *text == '\0')
		return E_FAIL;

	float xp = x, yp = y;
	D3DCOLOR clr = color;
	xp = x -= (float)m_chrSpacing;

	if (FAILED(this->BeginRender()))
		return E_FAIL;

	DWORD fvf;
	m_pD3Ddev->GetFVF(&fvf);
	m_pD3Ddev->SetFVF(D3DFVF_BITMAPFONT);
	m_pD3Ddev->SetTexture(0, m_pD3Dtex);
	m_pD3Ddev->SetStreamSource(0, m_pD3Dbuf, 0, sizeof(d3dvertex_s));

	UINT		usedTriangles = 0;
	d3dvertex_s *pVertex;

	if (FAILED(m_pD3Dbuf->Lock(0, 0, (void **)&pVertex, D3DLOCK_DISCARD)))
	{
		m_pD3Ddev->SetFVF(fvf);
		this->EndRender();
		return E_FAIL;
	}

	size_t len = strlen(text);
	for (size_t cpos = 0; cpos < len; cpos++)
	{
		if (text[cpos] == '\n')
		{
			xp = x;
			yp += DrawHeight();
			continue;
		}
		int c = (byte)(text[cpos]) - 32;
		if (!(c >= 0 && c < 224))
			continue;

		/*if ( text[cpos] == '{' && !noColorFormat )
		{
			stColorTag tag = GetColorTag( &text[cpos], len - cpos );
			if ( tag._valid )
			{
				if ( !skipColorTags )
				{
					clr = tag._color;
					if ( !tag._alpha )
						clr |= 0xFF000000;
				}
				cpos += tag._alpha ? 9 : 7;
				continue;
			}
		}*/

		float	tx1 = m_fTexCoords[c][0];
		float	tx2 = m_fTexCoords[c][2];
		float	ty1 = m_fTexCoords[c][1];
		float	ty2 = m_fTexCoords[c][3];
		float	w = (tx2 - tx1) * m_texWidth;
		float	h = (ty2 - ty1) * m_texHeight;

		*pVertex++ = Init2DVertex(xp - 0.5f, yp - 0.5f, clr, tx1, ty1);			//topleft
		*pVertex++ = Init2DVertex(xp + w - 0.5f, yp - 0.5f, clr, tx2, ty1);		//topright
		*pVertex++ = Init2DVertex(xp - 0.5f, yp + h - 0.5f, clr, tx1, ty2);		//bottomleft
		*pVertex++ = Init2DVertex(xp + w - 0.5f, yp - 0.5f, clr, tx2, ty1);		//topright
		*pVertex++ = Init2DVertex(xp + w - 0.5f, yp + h - 0.5f, clr, tx2, ty2);	//bottomright
		*pVertex++ = Init2DVertex(xp - 0.5f, yp + h - 0.5f, clr, tx1, ty2);		//bottomleft
		if (m_dwCreateFlags & FCR_BORDER)
			w -= 2.0f;

		xp += w - (m_chrSpacing * 2);
		usedTriangles += 2;
		if (usedTriangles >= m_maxTriangles)
			break;
	}
	m_pD3Dbuf->Unlock();
	if (usedTriangles > 0)
	{
		m_pD3Ddev->DrawPrimitive(D3DPT_TRIANGLELIST, 0, usedTriangles);
	}
	m_pD3Ddev->SetFVF(fvf);
	this->EndRender();

	return S_OK;
}

/*HRESULT CD3DFont::PrintShadow ( float x, float y, DWORD color, const char *szText )
{
	if (shadowEnable)
		Print(szText, D3DCOLOR_ARGB( ( byte ) HIBYTE( HIWORD( color ) ), 0, 0, 0 ), x + 1, y + 1, true, false);
	return Print(szText, color, x, y, false, false);
}*/

float CD3DFont::DrawLength(const char *szText/*, bool noColorFormat*/) const
{
	float	len = 0.0f;
	float	sub = (m_dwCreateFlags & FCR_BORDER) ? 2.0f : 0.0f;

	size_t strl = strlen(szText);
	for (size_t cpos = 0; cpos < strl && szText[cpos] != '\0'; cpos++)
	{
		int c = (byte)(szText[cpos]) - 32;
		if (!(c >= 0 && c < 224))
			continue;

		/*if ( szText[cpos] == '{' && !noColorFormat )
		{
			stColorTag tag = GetColorTag( &szText[cpos], strl - cpos );
			if ( tag._valid )
			{
				cpos += tag._alpha ? 9 : 7;
				continue;
			}
		}*/

		len += ((m_fTexCoords[c][2] - m_fTexCoords[c][0]) * m_texWidth - sub) - m_chrSpacing * 2;
	}
	return len;
}

size_t CD3DFont::GetCharPos(const char *text, float x/*, bool noColorFormat*/) const
{
	size_t pos = 0;
	float	len = 0.0f;
	float	sub = (m_dwCreateFlags & FCR_BORDER) ? 2.0f : 0.0f;

	size_t strl = strlen(text);
	for (size_t cpos = 0; cpos < strl && text[cpos] != '\0'; cpos++, pos++)
	{
		int c = (byte)(text[cpos]) - 32;
		if (!(c >= 0 && c < 224))
			continue;

		/*if ( text[cpos] == '{' && !noColorFormat )
		{
			stColorTag tag = GetColorTag( &text[cpos], strl - cpos );
			if ( tag._valid )
			{
				cpos += tag._alpha ? 9 : 7;
				continue;
			}
		}*/
		len += ((m_fTexCoords[c][2] - m_fTexCoords[c][0]) * m_texWidth - sub) - m_chrSpacing * 2;
		if (len >= x)
			break;
	}
	return pos;
}

CD3DRender::CD3DRender(int numVertices)
{
	m_canRender = false;

	m_pD3Dbuf = NULL;
	m_pVertex = NULL;

	m_color = 0;
	m_tu = 0.0f;
	m_tv = 0.0f;
	m_texture = NULL;

	m_maxVertex = numVertices;
	m_curVertex = 0;
}

CD3DRender::~CD3DRender()
{
	Invalidate();
}

HRESULT CD3DRender::Initialize(IDirect3DDevice9 *pD3Ddev)
{
	if (!m_canRender)
	{
		if (FAILED(CD3DBaseRender::Initialize(pD3Ddev)))
			return E_FAIL;
		if (FAILED(m_pD3Ddev->CreateVertexBuffer(m_maxVertex * sizeof(d3dvertex_s),
			D3DUSAGE_WRITEONLY | D3DUSAGE_DYNAMIC, 0, D3DPOOL_DEFAULT, &m_pD3Dbuf, NULL)))
			return E_FAIL;

		m_canRender = true;
	}

	return S_OK;
}

HRESULT CD3DRender::Invalidate()
{
	SAFE_RELEASE(m_pD3Dbuf);
	SAFE_RELEASE(m_texture);
	m_pVertex = NULL;

	CD3DBaseRender::Invalidate();
	m_canRender = false;

	return S_OK;
}

HRESULT CD3DRender::Begin(D3DPRIMITIVETYPE primType)
{
	if (!m_canRender)
		return E_FAIL;

	if (m_pVertex != NULL)
		return E_FAIL;

	if (FAILED(m_pD3Dbuf->Lock(0, 0, (void **)&m_pVertex, D3DLOCK_DISCARD)))
		return E_FAIL;

	m_primType = primType;

	return S_OK;
}

HRESULT CD3DRender::End()
{
	int numPrims;

	m_pVertex = NULL;

	if (!m_canRender)
	{
		m_curVertex = 0;
		return E_FAIL;
	}

	if (FAILED(CD3DBaseRender::BeginRender()))
		return E_FAIL;

	switch (m_primType)
	{
	case D3DPT_POINTLIST:
		numPrims = m_curVertex;
		break;

	case D3DPT_LINELIST:
		numPrims = m_curVertex / 2;
		break;

	case D3DPT_LINESTRIP:
		numPrims = m_curVertex - 1;
		break;

	case D3DPT_TRIANGLELIST:
		numPrims = m_curVertex / 3;
		break;

	case D3DPT_TRIANGLESTRIP:
	case D3DPT_TRIANGLEFAN:
		numPrims = m_curVertex - 2;
		break;

	default:
		numPrims = 0;
		break;
	}

	m_curVertex = 0;

	if (numPrims > 0)
	{
		m_pD3Dbuf->Unlock();

		DWORD	fvf;
		m_pD3Ddev->GetFVF(&fvf);

		if (m_texture == NULL)
		{
			m_pD3Ddev->SetFVF(D3DFVF_PRIMITIVES);
			m_pD3Ddev->SetTexture(0, NULL);
		}
		else
		{
			m_pD3Ddev->SetFVF(D3DFVF_BITMAPFONT);
			m_pD3Ddev->SetTexture(0, m_texture);
		}

		m_pD3Ddev->SetStreamSource(0, m_pD3Dbuf, 0, sizeof(d3dvertex_s));

		m_pD3Ddev->DrawPrimitive(m_primType, 0, numPrims);

		m_pD3Ddev->SetFVF(fvf);
	}

	CD3DBaseRender::EndRender();

	return S_OK;
}

HRESULT CD3DRender::D3DColor(DWORD color)
{
	m_color = color;
	return m_canRender ? S_OK : E_FAIL;
	return S_OK;
}

void CD3DRender::D3DBindTexture(IDirect3DTexture9 *texture)
{
	m_texture = texture;
}

void CD3DRender::D3DTexCoord2f(float u, float v)
{
	m_tu = u;
	m_tv = v;
}

HRESULT CD3DRender::D3DVertex2f(float x, float y)
{
	if (m_canRender && m_pVertex && ++m_curVertex < m_maxVertex)
		*m_pVertex++ = Init2DVertex(x, y, m_color, m_tu, m_tv);
	else
		return E_FAIL;

	return S_OK;
}

void CD3DRender::D3DTexQuad(float sx, float sy, float ex, float ey, float su, float sv, float eu, float ev)
{
	if (SUCCEEDED(Begin(D3DPT_TRIANGLELIST)))
	{
		D3DColor(D3DCOLOR_XRGB(255, 255, 255));
		D3DTexCoord2f(su, sv);
		D3DVertex2f(sx, sy);
		D3DTexCoord2f(eu, sv);
		D3DVertex2f(ex, sy);
		D3DTexCoord2f(su, ev);
		D3DVertex2f(sx, ey);

		D3DTexCoord2f(su, ev);
		D3DVertex2f(sx, ey);
		D3DTexCoord2f(eu, sv);
		D3DVertex2f(ex, sy);
		D3DTexCoord2f(eu, ev);
		D3DVertex2f(ex, ey);
		End();
	}
}

void CD3DRender::D3DBox(float x, float y, float w, float h, D3DCOLOR color)
{
	if (SUCCEEDED(Begin(D3DPT_TRIANGLELIST)))
	{
		D3DColor(color);
		D3DVertex2f(x, y);
		D3DVertex2f(x + w, y);
		D3DVertex2f(x, y + h);
		D3DVertex2f(x, y + h);
		D3DVertex2f(x + w, y);
		D3DVertex2f(x + w, y + h);
		End();
	}
}

void CD3DRender::D3DBoxBorder(float x, float y, float w, float h, D3DCOLOR border_color, D3DCOLOR color)
{
	D3DBox(x, y, w, h, color);
	if (SUCCEEDED(Begin(D3DPT_LINESTRIP)))
	{
		D3DColor(border_color);
		D3DVertex2f(x - 1, y - 1);
		D3DVertex2f(x + w, y - 1);
		D3DVertex2f(x + w, y + h);
		D3DVertex2f(x - 1, y + h);
		D3DVertex2f(x - 1, y - 1);
		End();
	}
}

void CD3DRender::D3DLine(int x, int y, int x2, int y2, D3DCOLOR color)
{
	if (SUCCEEDED(Begin(D3DPT_LINELIST)))
	{
		D3DColor(color);
		D3DVertex2f((float)x, (float)y);
		D3DVertex2f((float)x2, (float)y2);
		End();
	}
}

bool CD3DRender::DrawLine(const D3DXVECTOR3 &a, const D3DXVECTOR3 &b, DWORD dwColor)
{
	if (FAILED(CD3DBaseRender::BeginRender()))
		return false;

	////////////////////////////////////////////////////
	// Make sure we have a valid vertex buffer.
	if (m_pD3Dbuf == NULL)
	{
		return false;
	}

	m_pD3Ddev->SetTextureStageState(0, D3DTSS_COLOROP, D3DTOP_SELECTARG2);
	m_pD3Ddev->SetTextureStageState(0, D3DTSS_ALPHAOP, D3DTOP_SELECTARG2);
	//m_pD3Ddev->SetTextureStageState( 0, D3DTSS_COLORARG2, D3DTA_DIFFUSE );
	//m_pD3Ddev->SetTextureStageState( 0, D3DTSS_ALPHAARG2, D3DTA_DIFFUSE );

	m_pD3Ddev->SetRenderState(D3DRS_CLIPPING, false);
	m_pD3Ddev->SetRenderState(D3DRS_ZENABLE, false);
	//m_pD3Ddev->SetRenderState ( D3DRS_LIGHTING, false );
	D3DLVERTEX	lineList[2];

	//////////////////////////////////////////////////
	// Lock the vertex buffer and copy in the verts.
	m_pD3Dbuf->Lock(0, 0, (void **)&lineList, D3DLOCK_DISCARD | D3DLOCK_NOSYSLOCK); // flogs: D3DLOCK_NOSYSLOCK, D3DLOCK_DISCARD
	{
		lineList[0].x = a.x;
		lineList[0].y = a.y;
		lineList[0].z = a.z;
		lineList[0].color = dwColor;
		lineList[0].specular = dwColor;

		lineList[1].x = b.x;
		lineList[1].y = b.y;
		lineList[1].z = b.z;
		lineList[1].color = dwColor;
		lineList[1].specular = dwColor;
	}

	m_pD3Dbuf->Unlock();

	// store FVF to restore original at the end of this function
	DWORD		fvf;
	m_pD3Ddev->GetFVF(&fvf);
	m_pD3Ddev->SetFVF(D3DFVF_LVERTEX);
	//m_pD3Ddev->SetFVF( D3DFVF_PRIMITIVES );

	////////////////////////////////////////////////////
	// Draw!
	m_pD3Ddev->DrawPrimitiveUP(D3DPT_LINESTRIP, 1, lineList, sizeof(lineList) / 2);

	// reset states
	m_pD3Ddev->SetTextureStageState(0, D3DTSS_COLOROP, D3DTOP_MODULATE);
	m_pD3Ddev->SetTextureStageState(0, D3DTSS_ALPHAOP, D3DTOP_MODULATE);
	m_pD3Ddev->SetRenderState(D3DRS_ZENABLE, true);
	m_pD3Ddev->SetRenderState(D3DRS_CLIPPING, true);

	// restore FVF
	m_pD3Ddev->SetFVF(fvf);

	CD3DBaseRender::EndRender();

	return true;
}

void CD3DRender::D3DMSFlag(float x, float y, D3DCOLOR color)
{
	if (SUCCEEDED(Begin(D3DPT_TRIANGLELIST)))
	{
		D3DColor(color);

		D3DVertex2f(x + 6, y + 3);
		D3DVertex2f(x + 15, y + 7);
		D3DVertex2f(x + 6, y + 10);

		D3DVertex2f(x + 5, y + 3);
		D3DVertex2f(x + 6, y + 3);
		D3DVertex2f(x + 5, y + 15);

		D3DVertex2f(x + 5, y + 13);
		D3DVertex2f(x + 9, y + 16);
		D3DVertex2f(x + 1, y + 16);

		End();
	}
}

void CD3DRender::D3DMSMine(float x, float y, D3DCOLOR color)
{
	D3DBox(x + 5, y + 5, 8, 8, color);
	D3DBox(x + 8, y + 2, 2, 14, color);
	D3DBox(x + 2, y + 8, 14, 2, color);
	D3DLine((int)x + 4, (int)y + 3, (int)x + 15, (int)y + 14, color);
	D3DLine((int)x + 3, (int)y + 4, (int)x + 14, (int)y + 15, color);
	D3DLine((int)x + 3, (int)y + 13, (int)x + 14, (int)y + 2, color);
	D3DLine((int)x + 4, (int)y + 14, (int)x + 15, (int)y + 3, color);
}

D3DCOLOR col[8] = { 0xFF1F1FCC, 0xFF116600, 0xFF990F0F, 0xFFE5A422, 0xFF8A2EE5, 0xFF2E8AE5, 0xFF4D4D4D, 0xFFFF0073 };
void CD3DFont::PrintMSNum(BYTE num, float x, float y)
{
	if (num < 1 || num > 8)
		return;

	char cnum[2] = { num + '0', '\0' };

	Print(cnum, col[num - 1], x + ((22.0f - DrawLength(cnum)) / 2.0f), y + ((22.0f - DrawHeight()) / 2.0f) - 1.0f);
}

void CD3DRender::D3DMSDNum(int num, float x, float y, D3DCOLOR color)
{
	D3DCOLOR off = 0xFF4d000b;
	if (SUCCEEDED(Begin(D3DPT_TRIANGLELIST)))
	{
		D3DColor(color);

		// верх
		if (num != 1 && num != 4)
			D3DColor(color);
		else
			D3DColor(off);

		D3DVertex2f(x + 4, y + 2);
		D3DVertex2f(x + 21, y + 2);
		D3DVertex2f(x + 9, y + 7);

		D3DVertex2f(x + 9, y + 7);
		D3DVertex2f(x + 21, y + 2);
		D3DVertex2f(x + 16, y + 7);

		// верх лево
		if (num != 1 && num != 2 && num != 3 && num != 7)
			D3DColor(color);
		else
			D3DColor(off);

		D3DVertex2f(x + 2, y + 4);
		D3DVertex2f(x + 7, y + 9);
		D3DVertex2f(x + 2, y + 21);

		D3DVertex2f(x + 2, y + 21);
		D3DVertex2f(x + 7, y + 9);
		D3DVertex2f(x + 7, y + 16);

		// верх право
		if (num != 5 && num != 6)
			D3DColor(color);
		else
			D3DColor(off);

		D3DVertex2f(x + 18, y + 9);
		D3DVertex2f(x + 23, y + 4);
		D3DVertex2f(x + 18, y + 16);

		D3DVertex2f(x + 18, y + 16);
		D3DVertex2f(x + 23, y + 4);
		D3DVertex2f(x + 23, y + 21);

		// середина
		if (num != 0 && num != 1 && num != 7)
			D3DColor(color);
		else
			D3DColor(off);

		D3DVertex2f(x + 5, y + 22);
		D3DVertex2f(x + 7, y + 20);
		D3DVertex2f(x + 7, y + 24);

		D3DVertex2f(x + 18, y + 20);
		D3DVertex2f(x + 20, y + 22);
		D3DVertex2f(x + 17, y + 25);

		D3DVertex2f(x + 7, y + 20);
		D3DVertex2f(x + 18, y + 20);
		D3DVertex2f(x + 7, y + 25);

		D3DVertex2f(x + 7, y + 25);
		D3DVertex2f(x + 18, y + 20);
		D3DVertex2f(x + 18, y + 25);

		// низ лево
		if (num == 0 || num == 2 || num == 6 || num == 8)
			D3DColor(color);
		else
			D3DColor(off);

		D3DVertex2f(x + 2, y + 24);
		D3DVertex2f(x + 7, y + 29);
		D3DVertex2f(x + 2, y + 41);

		D3DVertex2f(x + 2, y + 41);
		D3DVertex2f(x + 7, y + 29);
		D3DVertex2f(x + 7, y + 36);

		// низ право
		if (num != 2)
			D3DColor(color);
		else
			D3DColor(off);

		D3DVertex2f(x + 18, y + 29);
		D3DVertex2f(x + 23, y + 24);
		D3DVertex2f(x + 18, y + 36);

		D3DVertex2f(x + 18, y + 36);
		D3DVertex2f(x + 23, y + 24);
		D3DVertex2f(x + 23, y + 41);

		// низ
		if (num != 1 && num != 4 && num != 7)
			D3DColor(color);
		else
			D3DColor(off);

		D3DVertex2f(x + 9, y + 38);
		D3DVertex2f(x + 16, y + 38);
		D3DVertex2f(x + 4, y + 43);

		D3DVertex2f(x + 4, y + 43);
		D3DVertex2f(x + 16, y + 38);
		D3DVertex2f(x + 21, y + 43);

		End();
	}
}

void CD3DRender::D3DMSSBox(int num, float x, float y, D3DCOLOR color0, D3DCOLOR color1)
{
	if (num < 0) num = 0;
	if (num > 999) num = 999;
	int num0 = num / 100 % 10;
	int num1 = num / 10 % 10;
	int num2 = num % 10;
	D3DBoxBorder(x, y, 76, 46, 0xFFDADBDC, color0);
	D3DMSDNum(num0, x + 1, y + 1, color1);
	D3DMSDNum(num1, x + 26, y + 1, color1);
	D3DMSDNum(num2, x + 51, y + 1, color1);
}

void CD3DRender::D3DMSRozha(float x, float y, int state)
{
	D3DRMR(x + 15.f, y + 15.f, 12.0f, 10.f, 0xFFFFFF00, 0xFF000000, true);

	switch (state)
	{
	case 0:
	case 1:
		D3DBox(x + 9, y + 8, 3, 3, 0xFF000000);
		D3DBox(x + 19, y + 8, 3, 3, 0xFF000000);
		if (SUCCEEDED(Begin(D3DPT_LINESTRIP)))
		{
			D3DColor(0xFF000000);
			D3DVertex2f(x + 10, y + 22);
			D3DVertex2f(x + 12, y + 24);
			D3DVertex2f(x + 18, y + 24);
			D3DVertex2f(x + 21, y + 21);
			End();
		}
		break;
	case 2:
		D3DLine((int)x + 7, (int)y + 8, (int)x + 12, (int)y + 10, 0xFF000000);
		D3DLine((int)x + 7, (int)y + 11, (int)x + 12, (int)y + 7, 0xFF000000);
		D3DLine((int)x + 18, (int)y + 11, (int)x + 23, (int)y + 7, 0xFF000000);
		D3DLine((int)x + 18, (int)y + 8, (int)x + 23, (int)y + 10, 0xFF000000);
		D3DLine((int)x + 11, (int)y + 23, (int)x + 20, (int)y + 23, 0xFF000000);
		D3DLine((int)x + 16, (int)y + 24, (int)x + 19, (int)y + 24, 0xFFFF0000);
		break;
	case 3:
		D3DLine((int)x + 3, (int)y + 8, (int)x + 28, (int)y + 8, 0xFF000000);
		if (SUCCEEDED(Begin(D3DPT_TRIANGLEFAN)))
		{
			D3DColor(0xFF000000);
			D3DVertex2f(x + 6, y + 9);
			D3DVertex2f(x + 14, y + 9);
			D3DVertex2f(x + 12, y + 12);
			D3DVertex2f(x + 8, y + 12);
			End();
		}
		if (SUCCEEDED(Begin(D3DPT_TRIANGLEFAN)))
		{
			D3DColor(0xFF000000);
			D3DVertex2f(x + 18, y + 9);
			D3DVertex2f(x + 26, y + 9);
			D3DVertex2f(x + 23, y + 12);
			D3DVertex2f(x + 20, y + 12);
			End();
		}
		if (SUCCEEDED(Begin(D3DPT_LINESTRIP)))
		{
			D3DColor(0xFF000000);
			D3DVertex2f(x + 13, y + 21);
			D3DVertex2f(x + 13, y + 23);
			D3DVertex2f(x + 14, y + 24);
			D3DVertex2f(x + 16, y + 24);
			D3DVertex2f(x + 17, y + 23);
			D3DVertex2f(x + 17, y + 20);
			End();
		}
		break;
	case 4:
		D3DBox(x + 9, y + 8, 3, 3, 0xFF000000);
		D3DBox(x + 19, y + 8, 3, 3, 0xFF000000);
		D3DBox(x + 12, y + 23, 6, 2, 0xFFFFFFFF);
		if (SUCCEEDED(Begin(D3DPT_LINESTRIP)))
		{
			D3DColor(0xFF000000);
			D3DVertex2f(x + 11, y + 22);
			D3DVertex2f(x + 19, y + 22);
			D3DVertex2f(x + 19, y + 24);
			D3DVertex2f(x + 17, y + 26);
			D3DVertex2f(x + 13, y + 26);
			D3DVertex2f(x + 11, y + 24);
			D3DVertex2f(x + 11, y + 22);
			End();
		}
		break;
	}
}

void CD3DRender::D3DRMR(float cx, float cy, float re, float ra, D3DCOLOR color, D3DCOLOR bcolor, bool border)
{
	float curect = 0.0f;// re * D3DX_PI / 180.f;
	if (SUCCEEDED(Begin(D3DPT_TRIANGLEFAN)))
	{
		D3DColor(color);
		D3DVertex2f(cx, cy);
		for (int i = 0; i <= re; ++i)
		{
			float fx = cx + ra * (float)cos(curect*D3DX_PI / 180.f) - ra * (float)sin(curect*D3DX_PI / 180.f);
			float fy = cy + ra * (float)cos(curect*D3DX_PI / 180.f) + ra * (float)sin(curect*D3DX_PI / 180.f);
			D3DVertex2f(fx, fy);
			curect += 360.f / re;
		}
		End();
	}

	if (border && SUCCEEDED(Begin(D3DPT_LINESTRIP)))
	{
		D3DColor(bcolor);
		for (int i = 0; i <= re; ++i)
		{
			float fx = cx + ra * cosf(curect*D3DX_PI / 180.f) - ra * sinf(curect*D3DX_PI / 180.f);
			float fy = cy + ra * cosf(curect*D3DX_PI / 180.f) + ra * sinf(curect*D3DX_PI / 180.f);
			D3DVertex2f(fx, fy);
			curect += 360.f / re;
		}
		End();
	}
}