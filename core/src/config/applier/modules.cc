/*
** Copyright 2011-2013 Centreon
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

#include "com/centreon/broker/config/applier/modules.hh"
#include <cassert>
#include <cstdlib>
#include <memory>
#include "com/centreon/broker/logging/logging.hh"
#include "com/centreon/broker/multiplexing/engine.hh"

using namespace com::centreon::broker::config::applier;

// Class instance.
static modules* gl_modules = nullptr;

/**************************************
 *                                     *
 *           Public Methods            *
 *                                     *
 **************************************/

/**
 *  Destructor.
 */
modules::~modules() {
  logging::debug(logging::high) << "module applier: destruction";
}

/**
 *  Apply a module configuration.
 *
 *  @param[in] module_list Module list.
 *  @param[in] module_dir  Module directory.
 *  @param[in] arg         Module argument.
 */
void modules::apply(std::list<std::string> const& module_list,
                    std::string const& module_dir,
                    void const* arg) {
  // FIXME DBR: Very strange those lines of code. The hook and unhook methods
  // are already locked, why add a lock?

//  // Lock multiplexing engine in case modules register hooks.
//  std::lock_guard<std::recursive_mutex> lock(
//      com::centreon::broker::multiplexing::engine::instance());

  // Load modules.
  for (std::string const& m : module_list) {
    logging::config(logging::high)
        << "module applier: loading module '" << m << "'";
    _loader.load_file(m, arg);
  }
  if (!module_dir.empty()) {
    logging::config(logging::high)
        << "module applier: loading directory '" << module_dir << "'";
    _loader.load_dir(module_dir, arg);
  } else
    logging::debug(logging::high) << "module applier: no directory defined";
}

/**
 *  Get iterator to the first module.
 *
 *  @return Iterator to the first module.
 */
modules::iterator modules::begin() {
  return _loader.begin();
}

/**
 *  Unload modules.
 */
void modules::discard() {
  _loader.unload();
}

/**
 *  Get last iterator of the module list.
 *
 *  @return Last iterator of the module list.
 */
modules::iterator modules::end() {
  return _loader.end();
}

/**
 *  Get the class instance.
 *
 *  @return Class instance.
 */
modules& modules::instance() {
  assert(gl_modules);
  return *gl_modules;
}

/**
 *  Load the singleton.
 */
void modules::load() {
  if (!gl_modules)
    gl_modules = new modules;
}

/**
 *  Unload the singleton.
 */
void modules::unload() {
  delete gl_modules;
  gl_modules = nullptr;
}

std::mutex& modules::module_mutex() {
  return _m_modules;
}
