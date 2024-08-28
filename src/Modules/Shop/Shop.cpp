#include "Modules/Shop/Shop.h"
#include "Global.h"
#include "Entry.h"

#include <filesystem>

using namespace std::filesystem;

namespace TSModules {
// 文件位置/对象
Shop::~Shop() {
    logger.debug("ShopClass 析构...");
    for (auto& [name, data] : ShopCache) {
        delete data;
    }
    ShopCache.clear();
}
Shop::Shop() { logger.debug("ShopClass 构造..."); }
::ShopData* Shop::getShopData(const std::string& shopName) {
    if (ShopCache[shopName] != nullptr) {
        return ShopCache[shopName];
    }
    ::ShopData* data = nullptr;
    auto filePath = Tellurium::Entry::getInstance().getSelf().getDataDir() / "shop" / shopName;
    if (!exists(filePath)) {

    } 

    return nullptr;
}
} // namespace TSModules