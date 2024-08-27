#include "Config/Config.h"
#include "Global.h"

#include <filesystem>
#include <ll/api/Config.h>

TSConfig::Config config;

namespace TSConfig {

auto ConfigDir = std::filesystem::path();

void loadConfig(const std::filesystem::path& path) {
    if (!ll::config::loadConfig(config, path)) {
        logger.warn("Old config file detected, upgrading...");
        saveConfig(path);
    }
}

void saveConfig(const std::filesystem::path& path) {
    if (!ll::config::saveConfig(config, path)) {
        logger.error("Failed to save config file.");
    }
}

void initConfig(ll::mod::NativeMod& self) {
    // init 以后不需要再次获取 ConfigDir 直接用即可 除非赋值失败
    ConfigDir = self.getConfigDir();
    loadConfig(getConfigPath());
};

const std::filesystem::path& getConfigDir() { return ConfigDir; };
const std::filesystem::path  getConfigPath() { return ConfigDir / "config.json"; };
} // namespace TSConfig
