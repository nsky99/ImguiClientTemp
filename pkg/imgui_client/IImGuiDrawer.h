#pragma once
class IImGuiDrawer {
public:
    virtual ~IImGuiDrawer() = default;
    virtual void Draw() = 0;  // »æÖÆUIµÄº¯Êý

public:
    HWND m_hwnd = NULL;
};

