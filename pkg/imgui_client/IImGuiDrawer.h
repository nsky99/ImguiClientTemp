#pragma once
class IImGuiDrawer {
public:
    virtual ~IImGuiDrawer() = default;
    virtual void Draw() = 0;  // ����UI�ĺ���

public:
    HWND m_hwnd = NULL;
};

