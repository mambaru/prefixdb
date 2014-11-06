#include <wfc/wfc.hpp>
#include <startup/startup_module.hpp>
#include <core/core_module.hpp>
#include <config/config_module.hpp>
#include <logger/logger_module.hpp>
#include <hub/hub_module.hpp>
#include <repli_hub/repli_hub_module.hpp>
#include <pubsub_service/pubsub_service_module.hpp>
#include <pubsub_gateway/pubsub_gateway_module.hpp>
//#include <core/build_info.h>
#include <module/leveldb_module.hpp>
#include "leveldbd_build_info.h"
          


int main(int argc, char* argv[])
{
  return wfc::wfc(
    leveldbd_build_info_string,
    {
      { "startup", std::make_shared< wfc::startup_module>() },
      { "core",    std::make_shared< wfc::core_module   >() },
      { "config",  std::make_shared< wfc::config_module >() },
      { "logger",  std::make_shared< wfc::logger_module >() }, 
      { "hub",     std::make_shared< wfc::hub_module    >() },
      { "repli-hub",       std::make_shared< wfc::repli_hub_module >()      },
      { "pubsub-service",  std::make_shared< wfc::pubsub_service_module >() },
      { "pubsub-gateway",  std::make_shared< wfc::pubsub_gateway_module >() }, 
      { "leveldb",    std::make_shared< wamba::leveldb::leveldb_module >()  }
    }
  ).run(argc, argv);
}
