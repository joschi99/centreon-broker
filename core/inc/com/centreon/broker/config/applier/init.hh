/*
** Copyright 2011 Centreon
**
** Licensed under the Apache License, Version 2.0 (the "License");
** you may not use this file except in compliance with the License.
** You may obtain a copy of the License at
**
**     http://www.apache.org/licenses/LICENSE-2.0
**
** Unless required by applicable law or agreed to in writing, software
** distributed under the License is distributed on an "AS IS" BASIS,
** WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
** See the License for the specific language governing permissions and
** limitations under the License.
**
** For more information : contact@centreon.com
*/

#ifndef CCB_CONFIG_APPLIER_INIT_HH_
#define CCB_CONFIG_APPLIER_INIT_HH_

#include <atomic>
#include "com/centreon/broker/config/state.hh"
#include "com/centreon/broker/namespace.hh"

CCB_BEGIN()

namespace config {
namespace applier {
enum applier_state { not_started, initialized, finished };
extern std::atomic<applier_state> mode;
void deinit();
void init(const config::state& conf);
void init(size_t n_thread, const std::string& name);
}  // namespace applier
}  // namespace config

CCB_END()

#endif /* !CCB_CONFIG_APPLIER_INIT_HH_ */
