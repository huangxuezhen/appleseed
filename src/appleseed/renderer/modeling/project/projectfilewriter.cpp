
//
// This source file is part of appleseed.
// Visit https://appleseedhq.net/ for additional information and resources.
//
// This software is released under the MIT license.
//
// Copyright (c) 2010-2013 Francois Beaune, Jupiter Jazz Limited
// Copyright (c) 2014-2018 Francois Beaune, The appleseedhq Organization
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//

// Interface header.
#include "projectfilewriter.h"

// appleseed.renderer headers.
#include "renderer/modeling/project/xmlprojectfilewriter.h"

// appleseed.foundation headers.
#include "foundation/string/string.h"

// Boost headers.
#include "boost/filesystem.hpp"

using namespace foundation;
namespace bf = boost::filesystem;

namespace renderer
{

//
// ProjectFileWriter class implementation.
//

bool ProjectFileWriter::write(
    Project&        project,
    const char*     filepath,
    const int       options,
    const char*     extra_comments)
{
    const auto ext = lower_case(bf::path(filepath).extension().string());

    if (ext == ".appleseedz")
        return XMLProjectFileWriter::write_packed_project_file(
            project,
            filepath,
            options,
            extra_comments);

    return XMLProjectFileWriter::write_plain_project_file(
        project,
        filepath,
        options,
        extra_comments);
}

}   // namespace renderer
