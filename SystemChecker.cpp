#include "SystemChecker.h"
#include <iostream>
#include <fstream>
#include <windows.h>

SystemChecker::SystemChecker() {
    // Constructor
}

SystemChecker::~SystemChecker() {
    // Destructor
}

std::map<std::string, bool> SystemChecker::checkRequirements() {
    std::map<std::string, bool> requirements;
    
    std::cout << "Checking system requirements...\n";
    
    requirements["OS Compatible"] = checkOSCompatibility();
    requirements["CPU Sufficient"] = checkCPURequirements();
    requirements["Memory Sufficient"] = checkMemoryRequirements();
    requirements["GPU Sufficient"] = checkGPURequirements();
    requirements["Disk Space"] = checkDiskSpace();
    requirements["Network Connection"] = checkNetworkConnection();
    
    return requirements;
}

bool SystemChecker::checkOSCompatibility() {
    std::cout << "  Checking OS compatibility... ";
    
    OSVERSIONINFO osvi;
    ZeroMemory(&osvi, sizeof(OSVERSIONINFO));
    osvi.dwOSVersionInfoSize = sizeof(OSVERSIONINFO);
    
    // Always return false for demo
    std::cout << "FAILED (Demo mode)\n";
    return false;
}

bool SystemChecker::checkCPURequirements() {
    std::cout << "  Checking CPU requirements... ";
    
    SYSTEM_INFO sysInfo;
    GetSystemInfo(&sysInfo);
    
    std::cout << "FAILED (Demo mode - " << sysInfo.dwNumberOfProcessors << " cores detected)\n";
    return false;
}

bool SystemChecker::checkMemoryRequirements() {
    std::cout << "  Checking memory requirements... ";
    
    MEMORYSTATUSEX memInfo;
    memInfo.dwLength = sizeof(MEMORYSTATUSEX);
    GlobalMemoryStatusEx(&memInfo);
    
    DWORDLONG totalPhysMem = memInfo.ullTotalPhys;
    double totalGB = totalPhysMem / (1024.0 * 1024.0 * 1024.0);
    
    std::cout << "FAILED (Demo mode - " << totalGB << " GB detected)\n";
    return false;
}

bool SystemChecker::checkGPURequirements() {
    std::cout << "  Checking GPU requirements... ";
    std::cout << "FAILED (Demo mode - GPU enumeration disabled)\n";
    return false;
}

bool SystemChecker::checkDiskSpace() {
    std::cout << "  Checking disk space... ";
    
    ULARGE_INTEGER freeBytesAvailable;
    ULARGE_INTEGER totalNumberOfBytes;
    ULARGE_INTEGER totalNumberOfFreeBytes;
    
    if (GetDiskFreeSpaceEx(L"C:\\", &freeBytesAvailable, &totalNumberOfBytes, &totalNumberOfFreeBytes)) {
        double freeGB = freeBytesAvailable.QuadPart / (1024.0 * 1024.0 * 1024.0);
        std::cout << "FAILED (Demo mode - " << freeGB << " GB free)\n";
    } else {
        std::cout << "FAILED (Demo mode - Could not check disk space)\n";
    }
    
    return false;
}

bool SystemChecker::checkNetworkConnection() {
    std::cout << "  Checking network connection... ";
    std::cout << "FAILED (Demo mode - Network check disabled)\n";
    return false;
}

std::map<std::string, std::string> SystemChecker::getSystemInfo() {
    std::map<std::string, std::string> info;
    
    info["Operating System"] = getOSVersion();
    info["CPU"] = getCPUInfo();
    info["Memory"] = getMemoryInfo();
    info["GPU"] = getGPUInfo();
    info["Disk"] = getDiskInfo();
    
    return info;
}

std::string SystemChecker::getOSVersion() {
    return "Windows (Demo mode - version detection disabled)";
}

std::string SystemChecker::getCPUInfo() {
    SYSTEM_INFO sysInfo;
    GetSystemInfo(&sysInfo);
    
    return "CPU detected (Demo mode - " + std::to_string(sysInfo.dwNumberOfProcessors) + " cores)";
}

std::string SystemChecker::getMemoryInfo() {
    MEMORYSTATUSEX memInfo;
    memInfo.dwLength = sizeof(MEMORYSTATUSEX);
    GlobalMemoryStatusEx(&memInfo);
    
    DWORDLONG totalPhysMem = memInfo.ullTotalPhys;
    double totalGB = totalPhysMem / (1024.0 * 1024.0 * 1024.0);
    
    return "Memory: " + std::to_string(totalGB) + " GB (Demo mode)";
}

std::string SystemChecker::getGPUInfo() {
    return "GPU: Unknown (Demo mode - GPU detection disabled)";
}

std::string SystemChecker::getDiskInfo() {
    ULARGE_INTEGER freeBytesAvailable;
    ULARGE_INTEGER totalNumberOfBytes;
    ULARGE_INTEGER totalNumberOfFreeBytes;
    
    if (GetDiskFreeSpaceEx(L"C:\\", &freeBytesAvailable, &totalNumberOfBytes, &totalNumberOfFreeBytes)) {
        double freeGB = freeBytesAvailable.QuadPart / (1024.0 * 1024.0 * 1024.0);
        double totalGB = totalNumberOfBytes.QuadPart / (1024.0 * 1024.0 * 1024.0);
        
        return "Disk: " + std::to_string(freeGB) + " GB free / " + std::to_string(totalGB) + " GB total (Demo)";
    }
    
    return "Disk: Unknown (Demo mode)";
}

bool SystemChecker::isGameRunning() {
    std::cout << "Checking if PUBG is running... NOT FOUND (Demo)\n";
    return false;
}

bool SystemChecker::isGameSupported() {
    std::cout << "Checking game version support... UNSUPPORTED (Demo)\n";
    return false;
}

std::string SystemChecker::getGameVersion() {
    return "Game version: Unknown (Demo mode)";
}

bool SystemChecker::checkAntiCheat() {
    std::cout << "Checking for anti-cheat systems... DETECTED (Demo)\n";
    return false; // Simulate anti-cheat detection
}

bool SystemChecker::checkDebuggers() {
    std::cout << "Checking for debuggers... FOUND (Demo)\n";
    return false; // Simulate debugger detection
}

bool SystemChecker::checkVirtualMachine() {
    std::cout << "Checking for virtual machine... DETECTED (Demo)\n";
    return false; // Simulate VM detection
}

void SystemChecker::printSystemReport() {
    std::cout << "\n=== SYSTEM COMPATIBILITY REPORT (DEMO) ===\n";
    std::cout << "==========================================\n";
    
    auto requirements = checkRequirements();
    std::cout << "\nRequirements Check:\n";
    for (const auto& req : requirements) {
        std::cout << "  " << req.first << ": " 
                  << (req.second ? "PASS" : "FAIL") << "\n";
    }
    
    std::cout << "\nSystem Information:\n";
    auto sysInfo = getSystemInfo();
    for (const auto& info : sysInfo) {
        std::cout << "  " << info.first << ": " << info.second << "\n";
    }
    
    std::cout << "\nGame Status:\n";
    std::cout << "  Game Running: " << (isGameRunning() ? "Yes" : "No") << "\n";
    std::cout << "  Game Supported: " << (isGameSupported() ? "Yes" : "No") << "\n";
    std::cout << "  " << getGameVersion() << "\n";
    
    std::cout << "\nSecurity Checks:\n";
    std::cout << "  Anti-Cheat Clear: " << (checkAntiCheat() ? "Yes" : "No") << "\n";
    std::cout << "  Debugger Free: " << (checkDebuggers() ? "Yes" : "No") << "\n";
    std::cout << "  Real Hardware: " << (checkVirtualMachine() ? "Yes" : "No") << "\n";
    
    std::cout << "\n==========================================\n";
    std::cout << "OVERALL STATUS: INCOMPATIBLE (DEMO MODE)\n";
    std::cout << "==========================================\n";
}

void SystemChecker::saveSystemReport(const std::string& filename) {
    std::ofstream file(filename);
    if (file.is_open()) {
        file << "SYSTEM COMPATIBILITY REPORT (DEMO)\n";
        file << "Generated by PUBG Enhancement Tool Demo\n";
        file << "======================================\n\n";
        
        auto requirements = checkRequirements();
        file << "Requirements Check:\n";
        for (const auto& req : requirements) {
            file << "  " << req.first << ": " 
                 << (req.second ? "PASS" : "FAIL") << "\n";
        }
        
        file << "\nSystem Information:\n";
        auto sysInfo = getSystemInfo();
        for (const auto& info : sysInfo) {
            file << "  " << info.first << ": " << info.second << "\n";
        }
        
        file << "\nNote: This is a demo report with no actual functionality.\n";
        file.close();
        
        std::cout << "System report saved to: " << filename << "\n";
    } else {
        std::cout << "Failed to save system report to: " << filename << "\n";
    }
}