#ifndef INVOKER_HPP_
#define INVOKER_HPP_

enum EConvention
{
	kCdeclcall,
	kStdcall,
	kThiscall,
};

namespace injector
{
	namespace invoker
	{
		template<EConvention>
		struct FunctionInvoker {};

		template<>
		struct FunctionInvoker<kCdeclcall>
		{
			template<typename ReturnType, typename ... Arguments>
			static inline ReturnType Invoke(detail::Pointer aTarget, Arguments... args)
			{
				return reinterpret_cast<ReturnType(__cdecl*)(Arguments...)>(aTarget.Get())(args...);
			}
		};

		template<>
		struct FunctionInvoker<kStdcall>
		{
			template<typename ReturnType, typename ... Arguments>
			static inline ReturnType Invoke(detail::Pointer aTarget, Arguments... args)
			{
				return reinterpret_cast<ReturnType(__stdcall*)(Arguments...)>(aTarget.Get())(args...);
			}
		};

		template<>
		struct FunctionInvoker<kThiscall>
		{
			template<typename ReturnType, typename ... Arguments>
			static inline ReturnType Invoke(detail::Pointer aTarget, Arguments... args)
			{
				return reinterpret_cast<ReturnType(__thiscall*)(Arguments...)>(aTarget.Get())(args...);
			}
		};

	} // !namespace invoker

	template<typename ReturnType, EConvention Convention, typename ... Arguments>
	static inline ReturnType CallFunction(detail::Pointer aTarget, Arguments... args)
	{
#ifdef _WIN32
		return invoker::FunctionInvoker<Convention>::template Invoke<ReturnType, Arguments...>(aTarget, args...);
#else
		return reinterpret_cast<ReturnType(*)(Arguments...)>(aTarget.Get())(args...);
#endif // _WIN32
	}

	template<typename ReturnType, typename ... Arguments>
	static inline ReturnType Call(detail::Pointer aTarget, Arguments... args)
	{
		return CallFunction<ReturnType, kCdeclcall>(aTarget, args...);
	}

	template<typename ReturnType, typename ... Arguments>
	static inline ReturnType CallStd(detail::Pointer aTarget, Arguments... args)
	{
		return CallFunction<ReturnType, kStdcall>(aTarget, args...);
	}

	template<typename ReturnType, typename ... Arguments>
	static inline ReturnType CallMethod(detail::Pointer aTarget, Arguments... args)
	{
		return CallFunction<ReturnType, kThiscall>(aTarget, args...);
	}

} // !namespace injector

#endif // !INVOKER_HPP_
