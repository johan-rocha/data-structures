/*
 * Copyright(C) 2022, André Macedo Rodrigues Alves <andremralves@gmail.com>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of version 2.1 of the GNU Lesser General Public License
 * as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it would be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 *
 */

#ifndef __combsortH__
#define __combsortH__
#include "ordenacaomacros.h"
void combsort(Item *,int,int);

#ifdef __combsortonly__
#define sort(v,l,r) combsort(v,l,r)
#endif

#endif
