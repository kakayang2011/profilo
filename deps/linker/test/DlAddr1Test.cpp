/**
 * Copyright 2004-present, Facebook, Inc.
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

#include <linkertests/test.h>

#include <link.h>
#include <gtest/gtest.h>

#include <linker/link.h>

int meaning_of_life() {
  return 42;
}

struct DlAddr1Test : public BaseTest { };

TEST_F(DlAddr1Test, testDladdr1) {
  ElfW(Sym) const* sym;
  Dl_info info;
  ASSERT_EQ(1, dladdr1((void*)&meaning_of_life, &info, (void**)&sym, RTLD_DL_SYMENT));
  ASSERT_EQ(&meaning_of_life, info.dli_saddr);
  ASSERT_NE(nullptr, sym);
  ASSERT_LT(0U, sym->st_size);
}
