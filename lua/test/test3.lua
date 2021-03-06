--
-- Copyright 2018-2020 Centreon
--
-- Licensed under the Apache License, Version 2.0 (the "License");
-- you may not use this file except in compliance with the License.
-- You may obtain a copy of the License at
--
--     http://www.apache.org/licenses/LICENSE-2.0
--
-- Unless required by applicable law or agreed to in writing, software
-- distributed under the License is distributed on an "AS IS" BASIS,
-- WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
-- See the License for the specific language governing permissions and
-- limitations under the License.
--
-- For more information : contact@centreon.com
--

broker_api_version = 2

-- Init function
function init(params)
  broker_log:set_parameters(1, "/tmp/test.log")
  for i,v in pairs(params) do
    broker_log:info(1, "init: " .. i .. " => " .. tostring(v))
  end
end

-- Write function
function write(d)
  for i,v in pairs(d) do
    broker_log:info(1, "write: " .. i .. " => " .. tostring(v))
  end
  return true
end

-- Filter function
function filter(typ, cat)
  return true
end
