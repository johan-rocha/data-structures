/*
 * Copyright(C) 2020, Bruno César Ribas <bruno.ribas@unb.br>
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
#include "ordenacaomacros.h"
#include "systemqsort.h"

int compar(const void *a,const void *b)
{
  if (less(*((Item*)a),*((Item*)b)))
    return -1;
  else if (lesseq(*((Item*)a),*((Item*)b)))
    return 0;
  return 1;
}
