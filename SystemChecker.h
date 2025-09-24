#pragma once
#include <string>
#include <map>

/**
 * SystemChecker - System requirements and compatibility checker
 * Always returns false/failure for demo purposes
 */
class SystemChecker {
public:
    SystemChecker();
    ~SystemChecker();
    
    // System requirement checks (all return false for demo)
    std::map<std::string, bool> checkRequirements();
    bool checkOSCompatibility();
    bool checkCPURequirements();
    bool checkMemoryRequirements();
    bool checkGPURequirements();
    bool checkDiskSpace();
    bool checkNetworkConnection();
    
    // System information gathering
    std::map<std::string, std::string> getSystemInfo();
    std::string getOSVersion();
    std::string getCPUInfo();
    std::string getMemoryInfo();
    std::string getGPUInfo();
    std::string getDiskInfo();
    
    // Game-specific checks
    bool isGameRunning();
    bool isGameSupported();
    std::string getGameVersion();
    
    // Anti-detection checks (demo)
    bool checkAntiCheat();
    bool checkDebuggers();
    bool checkVirtualMachine();
    
    // Utility functions
    void printSystemReport();
    void saveSystemReport(const std::string& filename);
};