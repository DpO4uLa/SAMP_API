#include "../DirectX/d3d9.h"
#include "../DirectX/d3dx9.h"
#pragma comment(lib, "../DirectX/d3dx9.lib")

class	CD3DFont;
class	CD3DRender;

#define FCR_NONE	0x0
#define FCR_BOLD	0x1
#define FCR_ITALICS 0x2
#define FCR_BORDER	0x4

//FVF Macros
#define D3DFVF_BITMAPFONT	( D3DFVF_XYZRHW | D3DFVF_DIFFUSE | D3DFVF_TEX1 )
#define D3DFVF_PRIMITIVES	( D3DFVF_XYZRHW | D3DFVF_DIFFUSE )

typedef struct d3dvertex_s
{
	float	x, y, z, rhw;
	DWORD	color;
	float	tu, tv;
} d3dvertex_s;

//Initialization Macros
#undef SAFE_RELEASE
#define SAFE_RELEASE( d ) \
	if ( d ) \
	{ \
		d->Release(); \
		d = NULL; \
	}

#define D3DFVF_XYZ			0x002
#define D3DFVF_RESERVED1	0x020
#define D3DFVF_DIFFUSE		0x040
#define D3DFVF_SPECULAR		0x080
#define D3DFVF_TEX1			0x100
#define D3DFVF_LVERTEX		( D3DFVF_XYZ | D3DFVF_RESERVED1 | D3DFVF_DIFFUSE | D3DFVF_SPECULAR | D3DFVF_TEX1 )

typedef float	D3DVALUE, *LPD3DVALUE;

typedef struct D3DLVERTEX
{
	union
	{
		D3DVALUE	x;			/* Homogeneous coordinates */
		D3DVALUE	dvX;
	};
	union
	{
		D3DVALUE	y;
		D3DVALUE	dvY;
	};
	union
	{
		D3DVALUE	z;
		D3DVALUE	dvZ;
	};
	DWORD	dwReserved;
	union
	{
		D3DCOLOR	color;		/* Vertex color */
		D3DCOLOR	dcColor;
	};
	union
	{
		D3DCOLOR	specular;	/* Specular component of vertex */
		D3DCOLOR	dcSpecular;
	};
	union
	{
		D3DVALUE	tu;			/* Texture coordinates */
		D3DVALUE	dvTU;
	};
	union
	{
		D3DVALUE	tv;
		D3DVALUE	dvTV;
	};
} D3DLVERTEX, *LPD3DLVERTEX;

class CD3DBaseRender
{
public:
	CD3DBaseRender ();
	~				CD3DBaseRender ();

	static HRESULT	BeginRender ();
	static HRESULT	EndRender ();
protected:
	static HRESULT				Initialize ( IDirect3DDevice9 *pD3Ddev );
	static HRESULT				Invalidate ();

	static HRESULT				CreateStates ();
	static HRESULT				DeleteStates ();

	static IDirect3DDevice9		*m_pD3Ddev;
	static IDirect3DStateBlock9 *m_pD3DstateDraw;
	static IDirect3DStateBlock9 *m_pD3DstateNorm;

	static int					m_renderCount;
	static int					m_numShared;
	static bool					m_statesOK;
};

class CD3DFont : public CD3DBaseRender
{
public:
	CD3DRender	*m_pRender;

	CD3DFont ( const char *szFontName, int fontHeight, DWORD dwCreateFlags );
	~			CD3DFont ();

	HRESULT		Initialize ( IDirect3DDevice9 *pD3Ddev );
	HRESULT		Invalidate ();

	HRESULT		Print( const char *text, D3DCOLOR color, float x, float y/*, bool skipColorTags, bool noColorFormat*/);
	void		PrintMSNum(BYTE n, float x, float y);

	float		DrawLength ( const char *szText/*, bool noColorFormat = false*/) const;
	size_t		GetCharPos( const char *text, float x/*, bool noColorFormat = false*/) const;

	float DrawHeight () const
	{
		return m_fChrHeight;
	};
private:
	char					m_szFontName[31 + 1];
	int						m_fontHeight;
	DWORD					m_dwCreateFlags;

	bool					m_isReady;

	IDirect3DTexture9		*m_pD3Dtex;
	IDirect3DVertexBuffer9	*m_pD3Dbuf;

	DWORD					m_maxTriangles;

	int						m_texWidth, m_texHeight;
	int						m_chrSpacing;
	float					m_fTexCoords[224][4];
	float					m_fChrHeight;
};

class CD3DRender : public CD3DBaseRender
{
public:
	CD3DRender ( int numVertices );
	~		CD3DRender ();

	HRESULT Initialize ( IDirect3DDevice9 *pD3Ddev );
	HRESULT Invalidate ();

	HRESULT Begin ( D3DPRIMITIVETYPE primType );
	HRESULT End ();

	HRESULT D3DColor ( DWORD color );
	void	D3DBindTexture ( IDirect3DTexture9 * );
	void	D3DTexCoord2f ( float u, float v );
	HRESULT D3DVertex2f ( float x, float y );

	void	D3DTexQuad ( float sx, float sy, float ex, float ey, float su, float sv, float eu, float ev );
	void	D3DBox ( float x, float y, float w, float h, D3DCOLOR color );
	void	D3DBoxBorder ( float x, float y, float w, float h, D3DCOLOR border_color, D3DCOLOR color );
	void	D3DLine(int x, int y, int x2, int y2, D3DCOLOR color);
	bool	DrawLine ( const D3DXVECTOR3 &a, const D3DXVECTOR3 &b, DWORD dwColor );

	void	D3DMSFlag(float x, float y, D3DCOLOR color);
	void	D3DMSMine(float x, float y, D3DCOLOR color);
	void	D3DMSDNum(int num, float x, float y, D3DCOLOR color);
	void	D3DMSSBox(int num, float x, float y, D3DCOLOR color0, D3DCOLOR color1);
	void	D3DMSRozha(float x, float y, int state);
	void	D3DRMR(float cx, float cy, float re, float ra, D3DCOLOR color, D3DCOLOR bcolor, bool border);
private:
	D3DPRIMITIVETYPE		m_primType;
	IDirect3DVertexBuffer9	*m_pD3Dbuf;
	d3dvertex_s				*m_pVertex;

	DWORD					m_color;
	float					m_tu, m_tv;
	IDirect3DTexture9		*m_texture;
	int						m_maxVertex;
	int						m_curVertex;

	bool					m_canRender;
};
