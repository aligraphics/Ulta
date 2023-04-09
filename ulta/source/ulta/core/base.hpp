#pragma once

#define BIT(x) (1 << x)

#define ULTA_BIND_EVENT_FN(fn) [this](auto&&... args) -> decltype(auto) { return this->fn(std::forward<decltype(args)>(args)...); }

namespace ulta {

	template<typename T>
	using scope = std::unique_ptr<T>;

	template<typename T, typename ... Args>
	constexpr scope<T> create_scope(Args&& ... args)
	{
		return std::make_unique<T>(std::forward<Args>(args)...);
	}

	template<typename T>
	using ref = std::shared_ptr<T>;
    
	template<typename T, typename ... Args>
	constexpr ref<T> create_ref(Args&& ... args)
	{
		return std::make_shared<T>(std::forward<Args>(args)...);
	}

}
