/*
 * Copyright (c) 2011 Joe Kopena <tjkopena@gmail.com>
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use, copy,
 * modify, merge, publish, distribute, sublicense, and/or sell copies
 * of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
 * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
 * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#ifndef __tj_template_h__
#define __tj_template_h__

#include "tj_buffer.h"

//----------------------------------------------------------------------
typedef struct tj_template_variables tj_template_variables;

tj_template_variables *
tj_template_variables_create(void);

void
tj_template_variables_finalize(tj_template_variables *vars);

void
tj_template_variables_setRecurse(tj_template_variables *vars,
                                 const char *label, char recurse);

int
tj_template_variables_setFromString(tj_template_variables *vars,
                                    const char *label,
                                    const char *substitution);

int
tj_template_variables_setFromFileStream(tj_template_variables *vars,
                                        const char *label, FILE *substitution);

int
tj_template_variables_setFromFile(tj_template_variables *vars,
                                  const char *label, const char *filename);

/*
 * Expand a template into a buffer, applying a set of variable
 * substitutions.
 *
 * \return 0 on failure, 1 otherwise.
 */
int
tj_template_variables_apply(tj_template_variables *variables,
                            tj_buffer *dest,
                            tj_buffer *src);

#endif // __tj_template_h__
