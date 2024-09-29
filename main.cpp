#include <windows.h>
#include "pkg/imgui_client/ImGuiClient.h"
#include "pkg/imgui_client/IImGuiDrawer.h"
#include <map>
#include <vector>
#include <algorithm>


class MyUI : public IImGuiDrawer {
public:
    MyUI() {
    }

    void Draw() override {
        if (false == m_mainwnd_open) {
            ::PostMessage(m_hwnd, WM_QUIT, 0, 0);
        }

        ImGui::SetNextWindowSize(ImVec2{ 1200,800 });
        if (ImGui::Begin("MainWnd", &m_mainwnd_open, ImGuiWindowFlags_NoCollapse)) {
            if (ImGui::BeginTabBar("main_tab", ImGuiTabBarFlags_DrawSelectedOverline)) {
                if (ImGui::BeginTabItem("process_tab")) {
                    ImGui::EndTabItem();
                }

                if (ImGui::BeginTabItem("thread_tab")) {
                    ImGui::EndTabItem();
                }
                ImGui::EndTabBar();
            }
        }
        ImGui::End();

    }

private:
    bool m_mainwnd_open = true;
};


int main() {
    ::ShowWindow(::GetConsoleWindow(), SW_HIDE);
    try {
        MyUI myUI;
        ImGuiClient client(L"MyWindowClass", L"Dear ImGui DirectX11 Example", myUI, 100, 100);
        client.Run();
    }
    catch (const std::exception& e) {
        MessageBoxA(nullptr, e.what(), "Error", MB_OK | MB_ICONERROR);
    }
    return 0;
}