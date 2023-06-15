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
#include "insertionsortslow.h"
#include "ordenacaomacros.h"

void insertionsortslow(Item *v,int l,int r)
{
  for(int i=l+1;i<=r;i++)
    for(int j=i;j>l;j--)
      cmpexch(v[j-1],v[j]);
}
