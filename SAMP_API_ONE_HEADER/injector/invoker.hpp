#ifndef INVOKER_HPP_
#define INVOKER_HPP_

enum class CallingConventions
{
	Cdecl,
	Stdcall,
	Thiscall,
};

namespace injector
{
	namespace invoker
	{
		template<CallingConventions>
		struct FunctionInvoker {};

		template<>
		struct FunctionInvoker<CallingConventions::Cdecl>
		{
			template<typename ReturnType, typename ... Arguments>
			static inline ReturnType Invoke(const detail::Pointer& aTarget, Arguments... args)
			{
				return aTarget.GetRaw<ReturnType(__cdecl*)(Arguments...)>()(args...);
			}
		};

		template<>
		struct FunctionInvoker<CallingConventions::Stdcall>
		{
			template<typename ReturnType, typename ... Arguments>
			static inline ReturnType Invoke(const detail::Pointer& aTarget, Arguments... args)
			{
				return aTarget.GetRaw<ReturnType(__stdcall*)(Arguments...)>()(args...);
			}
		};

		template<>
		struct FunctionInvoker<CallingConventions::Thiscall>
		{
			template<typename ReturnType, typename ... Arguments>
			static inline ReturnType Invoke(const detail::Pointer& aTarget, Arguments... args)
			{
				return aTarget.GetRaw<ReturnType(__thiscall*)(Arguments...)>()(args...);
			}
		};

	} // !namespace invoker

	template<typename ReturnType, CallingConventions Convention, typename ... Arguments>
	static inline ReturnType CallFunction(const detail::Pointer& aTarget, Arguments... args)
	{
#ifdef _WIN32
		return invoker::FunctionInvoker<Convention>::template Invoke<ReturnType, Arguments...>(aTarget, args...);
#else
		return aTarget.GetRaw<ReturnType(*)(Arguments...)>()(args...);
#endif // _WIN32
	}

	template<typename ReturnType, typename ... Arguments>
	static inline ReturnType Call(const detail::Pointer& aTarget, Arguments... args)
	{
		return CallFunction<ReturnType, CallingConventions::Cdecl>(aTarget, args...);
	}

	template<typename ReturnType, typename ... Arguments>
	static inline ReturnType CallStd(const detail::Pointer& aTarget, Arguments... args)
	{
		return CallFunction<ReturnType, CallingConventions::Stdcall>(aTarget, args...);
	}

	template<typename ReturnType, typename ... Arguments>
	static inline ReturnType CallMethod(const detail::Pointer& aTarget, Arguments... args)
	{
		return CallFunction<ReturnType, CallingConventions::Thiscall>(aTarget, args...);
	}

} // !namespace injector

#endif // !INVOKER_HPP_
