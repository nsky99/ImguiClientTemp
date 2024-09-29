#pragma once
#include <d3d11.h>
#include <tchar.h>
#include <stdexcept>
#include <string>
#include "imgui.h"
#include "imgui_impl_win32.h"
#include "imgui_impl_dx11.h"
#include "IImGuiDrawer.h"

#pragma  comment(lib,"D3D11.lib")


class ImGuiClient {
public:
    ImGuiClient(std::wstring className, std::wstring windowName, IImGuiDrawer& drawer, int width = 1280, int height = 800);

    ~ImGuiClient();

    void Run();

private:
    // d3d�豸
    ID3D11Device* m_d3dDevice = nullptr;
    ID3D11DeviceContext* m_d3dDeviceContext = nullptr;
    IDXGISwapChain* m_SwapChain = nullptr;
    ID3D11RenderTargetView* m_RenderTargetView = nullptr;
    ImVec4 m_clear_color; // �����һ�β�������ʹ�õ���ɫ
    bool m_SwapChainOccluded = false; // �����Ƿ��ڵ�

    // win32����
    HWND m_hwnd;
    std::wstring m_clsname;
    std::wstring m_wndname;

    IImGuiDrawer& m_drawer; // ��Ⱦ����

    bool m_done = false; // �Ƿ����imgui

private:

    void Render();

    bool CreateDeviceD3D(HWND hWnd) ;

    void CleanupDeviceD3D();

    void CreateRenderTarget();

    void CleanupRenderTarget() ;

    static LRESULT WINAPI StaticWndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) ;
};

