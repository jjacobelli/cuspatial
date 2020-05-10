/*
 * Copyright (c) 2019, NVIDIA CORPORATION.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#pragma once

#include <cudf/table/table.hpp>
#include <cudf/column/column_view.hpp>

namespace cuspatial {

/**
 * @brief read polygon data from an ESRI Shapefile.
 *
 * @param[in] filename: ESRI Shapefile file path (usually ends in .shp)
 * @param[in] mr:       Optional, The resource to use for all allocations
 *
 * @return Vector containing 4 columns representing one or more polygons:
 *  INT32:   beginning index of the first ring in each polygon
 *  INT32:   beginning index of the first point in each ring
 *  FLOAT64: x component of polygon points
 *  FLOAT64: y component of polygon points
 *
 * @note The number of polygons is equal to the length of the first column
 *
**/
std::vector<std::unique_ptr<cudf::column>>
read_polygon_shapefile(std::string const& filename rmm::mr::device_memory_resource* mr,);

} // namespace cuspatial
