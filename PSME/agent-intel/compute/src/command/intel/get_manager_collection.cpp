/*!
 * @section LICENSE
 *
 * @copyright
 * Copyright (c) 2015-2016 Intel Corporation
 *
 * @copyright
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * @copyright
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 * @copyright
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 * */

#include "agent-framework/command/compute/get_manager_collection.hpp"
#include "agent-framework/module-ref/compute_manager.hpp"

using namespace agent_framework::command;

/*! GetManagerCollection implementation */
class GetManagerCollection : public compute::GetManagerCollection {
public:
    using compute::GetManagerCollection::execute;
    using ComputeComponents = agent_framework::module::ComputeManager;

    void execute(const Request&, Response& response) {
        log_debug(GET_LOGGER("rpc"), "Getting collection of managers.");
        for (const auto& key : ComputeComponents::get_instance()->
                get_module_manager().get_keys("")) {
            response.add_manager(
                agent_framework::model::attribute::ManagerEntry(key));
        }
    }

    ~GetManagerCollection();
};

GetManagerCollection::~GetManagerCollection() {}

static Command::Register<GetManagerCollection> g("Intel");
