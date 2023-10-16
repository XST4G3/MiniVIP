#pragma once

template <typename T, int index, typename ...Args>
constexpr T CallVFunc(void* pThis, Args... args) noexcept
{
    return reinterpret_cast<T(*)(void*, Args...)> (reinterpret_cast<void***>(pThis)[0][index])(pThis, args...);
}

std::vector<uint32> explode(const std::string& s, const char& c)
{
	std::string buff{ "" };
	std::vector<uint32> v;

	for (auto n : s)
	{
		if (n != c) buff += n; else
			if (n == c && buff != "") { v.push_back(std::stoi(buff)); buff = ""; }
	}
	if (buff != "") v.push_back(std::stoi(buff));

	return v;
}

#ifdef _WIN32
#define WIN_LINUX(win, linux) win
#else
#define WIN_LINUX(win, linux) linux
#endif