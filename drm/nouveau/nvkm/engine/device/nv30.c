/*
 * Copyright 2012 Red Hat Inc.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
 * THE COPYRIGHT HOLDER(S) OR AUTHOR(S) BE LIABLE FOR ANY CLAIM, DAMAGES OR
 * OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 *
 * Authors: Ben Skeggs
 */
#include "priv.h"

int
nv30_identify(struct nvkm_device *device)
{
	switch (device->chipset) {
	case 0x30:
		device->oclass[NVDEV_ENGINE_FIFO   ] =  nv17_fifo_oclass;
		device->oclass[NVDEV_ENGINE_SW     ] =  nv10_sw_oclass;
		device->oclass[NVDEV_ENGINE_GR     ] = &nv30_gr_oclass;
		break;
	case 0x35:
		device->oclass[NVDEV_ENGINE_FIFO   ] =  nv17_fifo_oclass;
		device->oclass[NVDEV_ENGINE_SW     ] =  nv10_sw_oclass;
		device->oclass[NVDEV_ENGINE_GR     ] = &nv35_gr_oclass;
		break;
	case 0x31:
		device->oclass[NVDEV_ENGINE_FIFO   ] =  nv17_fifo_oclass;
		device->oclass[NVDEV_ENGINE_SW     ] =  nv10_sw_oclass;
		device->oclass[NVDEV_ENGINE_GR     ] = &nv30_gr_oclass;
		device->oclass[NVDEV_ENGINE_MPEG   ] = &nv31_mpeg_oclass;
		break;
	case 0x36:
		device->oclass[NVDEV_ENGINE_FIFO   ] =  nv17_fifo_oclass;
		device->oclass[NVDEV_ENGINE_SW     ] =  nv10_sw_oclass;
		device->oclass[NVDEV_ENGINE_GR     ] = &nv35_gr_oclass;
		device->oclass[NVDEV_ENGINE_MPEG   ] = &nv31_mpeg_oclass;
		break;
	case 0x34:
		device->oclass[NVDEV_ENGINE_FIFO   ] =  nv17_fifo_oclass;
		device->oclass[NVDEV_ENGINE_SW     ] =  nv10_sw_oclass;
		device->oclass[NVDEV_ENGINE_GR     ] = &nv34_gr_oclass;
		device->oclass[NVDEV_ENGINE_MPEG   ] = &nv31_mpeg_oclass;
		break;
	default:
		return -EINVAL;
	}

	return 0;
}
