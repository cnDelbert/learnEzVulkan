#ifndef VKBASE_H
#define VKBASE_H
#include "ezVulkanStart.h"

namespace ezVulkan
{
    class graphicsBase
    {
    public:
        static graphicsBase& Base()
        {
            return singleton;
        }
    private:
        static graphicsBase singleton;
        graphicsBase() = default;
        graphicsBase(const graphicsBase&&) = delete;
        ~graphicsBase() = default;
    };
    inline graphicsBase graphicsBase::singleton;
}
#endif //VKBASE_H
