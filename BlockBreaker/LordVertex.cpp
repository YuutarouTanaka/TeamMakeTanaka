#include "LordVertex.h"
#include "ManageRender.h"
void LordVertex(MnageRender* pRenderIns)
{
	pRenderIns->MakeVertex(1280.0, 960.0);
	pRenderIns->MakeVertex(1120.0, 300.0);
	pRenderIns->MakeVertex(400.0, 100.0);
	pRenderIns->MakeVertex(420.0, 120.0);
	pRenderIns->MakeVertex(80.0, 80.0);
	pRenderIns->MakeVertex(20.0, 20.0);
	pRenderIns->MakeVertex(150.0, 30.0);
	pRenderIns->MakeVertex(300.0, 100.0);
	pRenderIns->MakeAnimeVertex(100.0, 600.0, 8, 1);
	pRenderIns->MakeAnimeVertex(600.0, 100.0, 1, 7);
}