/*
����һ�����ʾ��
Ϊʲô�������Ҫ��������ܣ���Ҳ��֪����

*/


#include <windows.h>
#include <iostream>
#include <unordered_map>
#include <functional>

// ��������������õķ���
extern "C" __declspec(dllexport)
void RegisterCommands(std::unordered_map<std::string,
    std::function<int(int, char**)>>&cmd)
{
    cmd["hello"] = [](int argc, char** argv) -> int
        {
            if (argc == 1) {                  // ֻ��������
                std::cout << "Hello, World!\n";
                return 0;
            }
            std::cout << "Hello";
            for (int i = 1; i < argc; ++i) std::cout << " " << argv[i];
            std::cout << "!\n";
            return 0;
        };
}

// ��ѡ��DllMain ֻ��ռλ
BOOL APIENTRY DllMain(HMODULE hModule,
    DWORD  ul_reason_for_call,
    LPVOID lpReserved)
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}