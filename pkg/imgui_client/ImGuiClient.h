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
    // d3d设备
    ID3D11Device* m_d3dDevice = nullptr;
    ID3D11DeviceContext* m_d3dDeviceContext = nullptr;
    IDXGISwapChain* m_SwapChain = nullptr;
    ID3D11RenderTargetView* m_RenderTargetView = nullptr;
    ImVec4 m_clear_color; // 清除上一次残留像素使用的颜色
    bool m_SwapChainOccluded = false; // 窗口是否被遮挡

    // win32窗口
    HWND m_hwnd;
    std::wstring m_clsname;
    std::wstring m_wndname;

    IImGuiDrawer& m_drawer; // 渲染对象

    bool m_done = false; // 是否结束imgui

private:

    void Render();

    bool CreateDeviceD3D(HWND hWnd) ;

    void CleanupDeviceD3D();

    void CreateRenderTarget();

    void CleanupRenderTarget() ;

    static LRESULT WINAPI StaticWndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) ;
};

