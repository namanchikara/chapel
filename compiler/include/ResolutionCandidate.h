/*
 * Copyright 2004-2019 Cray Inc.
 * Other additional copyright holders may be indicated within.
 *
 * The entirety of this work is licensed under the Apache License,
 * Version 2.0 (the "License"); you may not use this file except
 * in compliance with the License.
 *
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

#ifndef _RESOLUTION_CANDIDATE_H_
#define _RESOLUTION_CANDIDATE_H_

#include "baseAST.h"
#include "vec.h"

#include <vector>

class ArgSymbol;
class CallInfo;
class FnSymbol;
class Symbol;


class ResolutionCandidate {
public:
                            ResolutionCandidate(FnSymbol* fn);

  bool                      isApplicable(CallInfo& info);

  FnSymbol*                 fn;
  std::vector<Symbol*>      formalIdxToActual;
  std::vector<ArgSymbol*>   actualIdxToFormal;

private:
                            ResolutionCandidate();

  bool                      isApplicableConcrete(CallInfo& info);

  void                      resolveTypeConstructor(CallInfo& info);

  bool                      isApplicableGeneric(CallInfo& info);

  bool                      computeAlignment(CallInfo& info);

  int                       computeSubstitutions();

  bool                      verifyGenericFormal(ArgSymbol* formal)       const;

  void                      computeSubstitution(ArgSymbol* formal,
                                                Symbol*    actual);

  void                      computeSubstitution(ArgSymbol* formal);

  void                      resolveTypedefedArgTypes();

  bool                      checkResolveFormalsWhereClauses(CallInfo& info);

  bool                      checkGenericFormals();

  SymbolMap                 substitutions;
};


void explainGatherCandidate(const CallInfo&            info,
                            Vec<ResolutionCandidate*>& candidates);

#endif
