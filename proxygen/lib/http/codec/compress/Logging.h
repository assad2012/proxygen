/*
 *  Copyright (c) 2016, Facebook, Inc.
 *  All rights reserved.
 *
 *  This source code is licensed under the BSD-style license found in the
 *  LICENSE file in the root directory of this source tree. An additional grant
 *  of patent rights can be found in the PATENTS file in the same directory.
 *
 */
#pragma once

#include <list>
#include <ostream>
#include <proxygen/lib/http/codec/compress/HeaderTable.h>
#include <vector>

namespace proxygen {

std::ostream& operator<<(std::ostream& os, const std::list<uint32_t>* refset);

std::ostream& operator<<(std::ostream& os, const std::vector<HPACKHeader> &v);

/**
 * print the difference between 2 sorted list of headers
 */
std::string printDelta(const std::vector<HPACKHeader> &v1,
                       const std::vector<HPACKHeader> &v2);

}
