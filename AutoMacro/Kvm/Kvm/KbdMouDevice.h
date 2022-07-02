#pragma once
#include <Windows.h>

namespace AutoMacro {
namespace Impl {
class KbdMouDevice {
 public:
    explicit KbdMouDevice(PCWSTR deviceInterface);
    virtual ~KbdMouDevice() = default;
    KbdMouDevice(const KbdMouDevice&) = delete;
    void operator =(const KbdMouDevice&) = delete;

    virtual void initialize();
    virtual void abort();

    bool isInitialized() const;
    bool isAborted() const;

 protected:
    void setOutputReport(PVOID data, DWORD size);

 private:
    PCWSTR mp_deviceInterface = nullptr;
    HANDLE mp_deviceHandle = nullptr;
    bool m_isInitialized = false;
    bool m_isAborted = false;
};
}  // namespace Impl
}  // namespace AutoMacro
