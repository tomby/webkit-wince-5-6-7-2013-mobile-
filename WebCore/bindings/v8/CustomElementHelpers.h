/*
 * Copyright (C) 2012 Google Inc. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *
 *     * Redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above
 * copyright notice, this list of conditions and the following disclaimer
 * in the documentation and/or other materials provided with the
 * distribution.
 *     * Neither the name of Google Inc. nor the names of its
 * contributors may be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef CustomElementHelpers_h
#define CustomElementHelpers_h

#include "ExceptionCode.h"
#include "ScriptValue.h"
#include <wtf/Forward.h>

namespace WebCore {

#if ENABLE(CUSTOM_ELEMENTS)

class CustomElementConstructor;
class CustomElementInvocation;
class Element;
class QualifiedName;
class ScriptState;

class CustomElementHelpers {
public:
    static bool initializeConstructorWrapper(CustomElementConstructor*, const ScriptValue& prototype, ScriptState*);
    static bool isValidPrototypeParameter(const ScriptValue&, ScriptState*);
    static bool isFeatureAllowed(ScriptState*);
    static const QualifiedName* findLocalName(const ScriptValue& prototype);

    static bool isFeatureAllowed(v8::Handle<v8::Context>);
    static WrapperTypeInfo* findWrapperType(v8::Handle<v8::Value> chain);
    static const QualifiedName* findLocalName(v8::Handle<v8::Object> chain);

    static void invokeReadyCallbacksIfNeeded(ScriptExecutionContext*, const Vector<CustomElementInvocation>&);

private:
    static void invokeReadyCallbackIfNeeded(Element*, v8::Handle<v8::Context>);
};

#endif // ENABLE(CUSTOM_ELEMENTS)

} // namespace WebCore

#endif // CustomElementHelpers_h