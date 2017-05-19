/*
 * Copyright 2017 Red Hat Inc.
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
 */
#include "nv50.h"
#include "head.h"
#include "ior.h"
#include "rootnv50.h"

static const struct nv50_disp_func
mcp89_disp = {
	.intr = nv50_disp_intr,
	.uevent = &nv50_disp_chan_uevent,
	.super = nv50_disp_super,
	.root = &gt215_disp_root_oclass,
	.head.new = nv50_head_new,
	.outp.internal.crt = nv50_dac_output_new,
	.outp.internal.tmds = nv50_sor_output_new,
	.outp.internal.lvds = nv50_sor_output_new,
	.outp.internal.dp = g94_sor_dp_new,
	.outp.external.tmds = nv50_pior_output_new,
	.outp.external.dp = nv50_pior_dp_new,
	.dac = { .nr = 3, .new = nv50_dac_new },
	.sor.nr = 4,
	.sor.new = mcp89_sor_new,
	.sor.hda_eld = gt215_hda_eld,
	.sor.hdmi = gt215_hdmi_ctrl,
	.pior = { .nr = 3, .new = nv50_pior_new },
};

int
mcp89_disp_new(struct nvkm_device *device, int index, struct nvkm_disp **pdisp)
{
	return nv50_disp_new_(&mcp89_disp, device, index, 2, pdisp);
}