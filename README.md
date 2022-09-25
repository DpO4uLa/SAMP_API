<a id="main"></a>

> ## Документация к SDK
---

> ### Быстрый доступ
> - #### [Установка Plugin SDK](#psdk)
> - #### [Настройка проекта](#setting)
> - #### [Отправка пакетов / RPC](#send)
> - #### [Эмулирование пакетов / RPC](#recv)
> - #### [Регистрация коллбеков](#callback)
> - #### [Работа с самп ид через Plugin SDK](#psdk_samp)
> - #### [Выбор версии SA-MP для компиляции](#sampver)
> - #### [Пример кода под две версии](#multicode)
> - #### [Регистрация коллбека через лямбду](#lambda)
---

<a id="psdk"></a>
> ### Установка Plugin SDK
> - Переходим по ссылке https://github.com/DK22Pac/plugin-sdk
> - Скачиваем проект с репозитория, далее выполняем шаги, находящиеся по ссылке https://github.com/DK22Pac/plugin-sdk/wiki/Set-up-plugin-sdk
> - Если все шаги выполнены верно, то в папке Plugin SDK появится файл `plugin.sln`, его нужно открыть, после чего запустится проект в Visual Studio
> - Сверху устанавливаем параметры компиляции - `Release`и чуть правее `Win32`, затем в обозревателе решений кликаем правой кнопкой мыши по `plugin_sa`, после чего выбираем пункт `Свойства`
> - В открывшемся окне настроек переходим в `Свойства конфигурации -> Общие`, устанавливаем имеющийся `Набор инструментов платфомы`, после этого, чуть выше, будет пункт `Версия пакета SDK для Windows`, там выбираем `"последнюю установленную версию"`
> - Переходим во вкладку `Свойства конфигурации -> Дополнительно`, в поле `Набор символов` устанавливаем значение `Использовать многобайтовую кодировку`, чуть ниже, в поле `Оптимизация всей программы` устанавливаем значение `Использовать создание кода во время компоновки`
> - Переходим во вкладку `C/C++ -> Общие`, в поле `Многопроцессорная компиляция` устанавливем значение `Да (/MP)`
> - Переходим во вкладку `C/C++ -> Оптимизация`, дальше с самого начала проставляем следующие настройки
>> Название | Настройка
>> :-------:|:--------:
>> `Оптимизация`|`Максимальная оптимизация (приоритет скорости) (/O2)`
>> `Развертывание подставляемых функций`|`Любой подходящий (/Ob2)`
>> `Включить подставляемые функции`|`Да (/Oi)`
>> `Предпочитать размер или скорость`|`Предпочитать краткость кода (/Os)`
>> `Опустить указатели на фреймы`|`Да (/Oy)`
>> `Включить волоконно-безопасные оптимизации`|`Нет`
>> `Оптимизация всей программы`|`Нет`
> - Переходим во вкладку `C/C++ -> Создание кода`, в поле `Библиотека времени выполнения` ставим `Многопоточная (/MT)`
> - После всех выполненых действий сохраняем настройки, затем в обозревателе решений нажимаем ПКМ по plugin_sa, после чего выбираем пункт `Собрать`
> - После успешной компиляции можно закрывать проект Plugin SDK, в папаке `output\lib\` должен появиться файл `plugin.lib`
> - [Вверх](#main)
---
<a id="setting"></a>
> ### Настройка проекта
> - Скачиваем проект, распаковываем, открываем файл `SAMP_API_ONE_HEADER.sln`
> - Ставим `Release` `x86`
> - Сверху нажимаем `Проект`, выбираем пункт `Свойства`
> - В открывшемся окне переходим в `Свойства конфигурации -> Общие`, выбираем имеющийся `Набор инструментов платформы`, затем `Стандарт языка C++` ставим `Стандарт ISO C++17 (/std:c++17)` и устанавливаем последнюю `"Версию пакета SDK для Windows"`, затем сохраняем настройки и нажимаем `Сборка`, выбираем пункт `Построить SAMP_API_ONE_HEADER`, если вы настроили всё правильно, то плагин скомпилируется и появится в папке `Release`
> - [Вверх](#main)
---
<a id="send"></a>
> ### Отправка пакетов / RPC
> - Реализация простейшей OnFoot рванки 
>> ```
>> auto CheatRvanka(void) -> void {
>> 	stOnFootData data = SAMP::pSAMP->getPlayers()->pLocalPlayer->onFootData;
>> 	data.fMoveSpeed[0] = 1.0f;
>> 	data.fMoveSpeed[1] = 1.0f;
>> 	data.fMoveSpeed[2] = 1.0f;
>> 	BitStream bs;
>> 	bs.Write<unsigned __int8>(ID_PLAYER_SYNC);
>> 	bs.Write((PCHAR)&data, sizeof(stOnFootData));
>> 	SAMP::pSAMP->getRakNet()->Send(&bs);
>> }
>> ```
> - Отправка рпц 
>>```
>>auto FuncSendMessage(void) -> void {
>>	std::string message("hello");
>>	BitStream bs;
>>	bs.Write((unsigned __int8)message.length());
>>	bs.Write(message.c_str(), message.length());
>>	SAMP::pSAMP->getRakNet()->SendRPC(RPC_Chat, &bs);
>>}
>>```
> - [Вверх](#main)
---
<a id="recv"></a>
> ### Эмулирование пакетов / RPC
> - Реализация фейковой входящей OnFoot синхры 
>>```
>>auto CheatFakeSync(void) -> void {
>>	stOnFootData data = SAMP::pSAMP->getPlayers()->pLocalPlayer->onFootData;
>>	BitStream bs;
>>	bs.Write<unsigned __int8>(ID_PLAYER_SYNC);
>>	bs.Write<unsigned __int16>(49);//playerID
>>	bs.Write((PCHAR)&data, sizeof(stOnFootData));
>>	SAMP::pSAMP->getRakNet()->EmulPacket(&bs);
>>}
>>```
> - Эмуляция рпц 
>>```
>>auto CheatEmulRPC(void) -> void {
>>	BitStream bs;
>>	bs.Write<float>(0.0f);
>>	bs.Write<float>(0.0f);
>>	bs.Write<float>(0.5f);
>>	SAMP::pSAMP->getRakNet()->EmulRPC(RPC_ScrSetPlayerVelocity, &bs);
>>}
>>```
> - [Вверх](#main)
---
<a id="callback"></a>
> ### Регистрация коллбеков
> - Регистрация RakNet коллбеков
>>```
>>//хук исходящих пакетов
>>bool __stdcall RakClientSendHook(SAMP::CallBacks::HookedStructs::stRakClientSend *params) {
>>
>>	if (params->bitStream->GetData()[0] == ID_PLAYER_SYNC) {
>>		params->bitStream->ResetReadPointer();
>>		params->bitStream->IgnoreBits(8);
>>		stOnFootData data = { 0 };
>>		params->bitStream->Read((PCHAR)&data, sizeof(stOnFootData));
>>
>>		//data.fMoveSpeed[2] = 1.0f;
>>
>>		params->bitStream->ResetWritePointer();
>>		params->bitStream->Write<unsigned __int8>(ID_PLAYER_SYNC);
>>		params->bitStream->Write((PCHAR)&data, sizeof(stOnFootData));
>>	}
>>
>>	return true;
>>}
>>
>>//хук входящих пакетов
>>bool __stdcall RakClientRecvHook(SAMP::CallBacks::HookedStructs::stRakClientRecv *params) {
>>
>>	return true;
>>}
>>
>>//хук исходящих RPC
>>bool __stdcall RakClientRPCHook(SAMP::CallBacks::HookedStructs::stRakClientRPC *params) {
>>
>>	return true;
>>}
>>
>>//хук входящих RPC
>>bool __stdcall RakClientRPCRecvHook(SAMP::CallBacks::HookedStructs::stRakClientRPCRecv *params) {
>>
>>	return true;
>>}
>>```
> - Сама регистация (регистрировать 1 раз, имеется возможность регистрации нескольких коллбеков одного типа, к примеру два коллбека D3D Present )
>>```
>>SAMP::CallBacks::pCallBackRegister->RegisterRakClientCallback(RakClientSendHook);//registed RakClient Send Hook
>>SAMP::CallBacks::pCallBackRegister->RegisterRakClientCallback(RakClientRecvHook);//registed RakClient Recv Hook
>>SAMP::CallBacks::pCallBackRegister->RegisterRakClientCallback(RakClientRPCHook);//registed RakClient RPC Hook
>>SAMP::CallBacks::pCallBackRegister->RegisterRakClientCallback(RakClientRPCRecvHook);//registed RakClient RPC recv Hook
>>```
> - Аналогично, регистрация GameLoop, WndProc, D3DPresent, D3DReset коллбеков
>>```
>>LRESULT __stdcall WndProcCallBack(SAMP::CallBacks::HookedStructs::stWndProcParams *params) {
>>	
>>	if (isPluginInitialized) {
>>		
>>	}
>>
>>	return 0;//retn null if all good
>>}
>>
>>HRESULT __stdcall D3DPresentHook(SAMP::CallBacks::HookedStructs::stPresentParams *params) {
>>
>>	if (isPluginInitialized) {
>>
>>
>>	}
>>
>>	return D3D_OK;
>>}
>>
>>HRESULT __stdcall D3DResetHook(SAMP::CallBacks::HookedStructs::stResetParams *params) {
>>
>>	if (isPluginInitialized) {
>>		
>>	}
>>
>>	return D3D_OK;
>>}
>>
>>void __stdcall GameLoop() {
>>    
>>}
>>```
> - Сама регистрация
>>```
>>SAMP::CallBacks::pCallBackRegister->RegisterGameLoopCallback(GameLoop);//register gameloop hook
>>SAMP::CallBacks::pCallBackRegister->RegisterWndProcCallback(WndProcCallBack);//register wnd proc hook
>>SAMP::CallBacks::pCallBackRegister->RegisterD3DCallback(D3DPresentHook);//register D3D present hook
>>SAMP::CallBacks::pCallBackRegister->RegisterD3DCallback(D3DResetHook);//register D3D reset hook
>>```
> - [Вверх](#main)
---
<a id="psdk_samp"></a>
> ### Работа с самп ид через Plugin SDK
>>```
>>//получить указатель на CPed* через ид игрока
>>CPed* pPed = SAMP::pSAMP->getPlayers()->GetCPedFromPlayerID(100);
>>		
>>//получить указатель на CVehicle* через ид машины
>>CVehicle* pVehicle = SAMP::pSAMP->getVehicles()->GetCVehicleFromSAMPVehicleID(100);
>>```
> - [Вверх](#main)
---
<a id="sampver"></a>
> ### Выбор версии SA-MP для компиляции
> - Открываем ностройки проекта, переходим в `C/C++ -> Препроцессор`, в пункте `Определения препроцессора` есть строка `SAMP_R1_COMPILE`. В зависимости от того, `R1` или `R3`, проект будет компилироваться под нужную версию сампа, возможные версии компиляции:
> - `SAMP_R1_COMPILE` - скомпилируется под 0.3.7-R1
> - `SAMP_R3_COMPILE` - скомпилируется под 0.3.7-R3-1
> - [Вверх](#main)
---
<a id="multicode"></a>
> ### Пример кода под две версии сампа
> - Вывод ников игроков в зоне стрима через ImGui::Text
>> ``` 
>>for (int i = 0; i != SAMP_MAX_PLAYERS; i++) {
>>	if (!SAMP::pSAMP->getPlayers()->IsPlayerStreamed(i))
>>		continue;
>>#if defined (SAMP_R1_COMPILE)//R1
>>	ImGui::Text("name of %d: %s", i, SAMP::pSAMP->getPlayers()->pRemotePlayer[i]->szPlayerName);
>>#elif defined (SAMP_R3_COMPILE)//R3
>>	ImGui::Text("name of %d: %s", i, SAMP::pSAMP->getPlayers()->pRemotePlayer[i]->PlayerName.c_str());
>>#endif			
>>}
>>```
> - [Вверх](#main)
---
<a id="lambda"></a>
> ### Пример регистрации коллбека через лямбду
>>```
>>class MainClass {
>>public:
>>	MainClass() {
>>		//RakNet Send
>>		*SAMP::CallBacks::pCallBackRegister += [&](SAMP::CallBacks::HookedStructs::stRakClientSend* params) -> bool {
>>
>>
>>			return true;
>>		};
>>		//GameLoop
>>		*SAMP::CallBacks::pCallBackRegister += [&]() -> void {
>>
>>
>>
>>		};
>>	};
>>
>>} MainClassObj;
>>```
> - [Вверх](#main)
