/**
 *    Copyright (C) 2019-present MongoDB, Inc.
 *
 *    This program is free software: you can redistribute it and/or modify
 *    it under the terms of the Server Side Public License, version 1,
 *    as published by MongoDB, Inc.
 *
 *    This program is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *    Server Side Public License for more details.
 *
 *    You should have received a copy of the Server Side Public License
 *    along with this program. If not, see
 *    <http://www.mongodb.com/licensing/server-side-public-license>.
 *
 *    As a special exception, the copyright holders give permission to link the
 *    code of portions of this program with the OpenSSL library under certain
 *    conditions as described in each individual source file and distribute
 *    linked combinations including the program with the OpenSSL library. You
 *    must comply with the Server Side Public License in all respects for
 *    all of the code used other than as permitted herein. If you modify file(s)
 *    with this exception, you may extend this exception to your version of the
 *    file(s), but you are not obligated to do so. If you do not wish to do so,
 *    delete this exception statement from your version. If you delete this
 *    exception statement from all source files in the program, then also delete
 *    it in the license file.
 */

#pragma once

#include "mongo/logv2/log_component.h"
#include "mongo/logv2/log_manager.h"
#include "mongo/logv2/log_tag.h"

namespace mongo {
namespace logv2 {

class LogOptions {
public:
    LogOptions() {}

    LogOptions(LogComponent component) : _component(component) {}

    LogOptions(LogDomain* domain) : _domain(domain) {}

    LogOptions(LogTag tags) : _tags(tags) {}

    LogOptions(LogComponent component, LogDomain* domain, LogTag tags)
        : _domain(domain), _tags(tags), _component(component) {}

    LogComponent component() const {
        return _component;
    }

    LogDomain& domain() const {
        return *_domain;
    }

    LogTag tags() const {
        return _tags;
    }

private:
    LogDomain* _domain = &LogManager::global().getGlobalDomain();
    LogTag _tags;
#ifdef MONGO_LOGV2_DEFAULT_COMPONENT
    LogComponent _component = MongoLogV2DefaultComponent_component;
#else
    LogComponent _component = LogComponent::kDefault;
#endif  // MONGO_LOGV2_DEFAULT_COMPONENT
};

}  // namespace logv2
}  // namespace mongo
