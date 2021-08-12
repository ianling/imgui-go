#pragma once

#include "Types.h"
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

extern int iggDrawListGetCommandCount(IggDrawList handle);
extern IggDrawCmd iggDrawListGetCommand(IggDrawList handle, int index);
extern void iggDrawListGetRawIndexBuffer(IggDrawList handle, void **data, int *byteSize);
extern void iggDrawListGetRawVertexBuffer(IggDrawList handle, void **data, int *byteSize);

extern void iggGetIndexBufferLayout(size_t *entrySize);
extern void iggGetVertexBufferLayout(size_t *entrySize, size_t *posOffset, size_t *uvOffset, size_t *colOffset);

extern void iggAddLine(IggDrawList handle, IggVec2 const *p1, IggVec2 const *p2, IggPackedColor col, float thickness);
extern void iggAddRect(IggDrawList handle, IggVec2 const *min, IggVec2 const *max, IggPackedColor col, float rounding, int flags, float thickness);
extern void iggAddRectFilled(IggDrawList handle, IggVec2 const *min, IggVec2 const *max, IggPackedColor col, float rounding, int flags);
extern void iggAddCircle(IggDrawList handle, IggVec2 const *center, float radius, IggPackedColor col, int numSegments, float thickness);
extern void iggAddCircleFilled(IggDrawList handle, IggVec2 const *center, float radius, IggPackedColor col, int numSegments);
extern void iggAddTriangle(IggDrawList handle, IggVec2 *p1, IggVec2 *p2, IggVec2 *p3, IggPackedColor col, float thickness);
extern void iggAddTriangleFilled(IggDrawList handle, IggVec2 *p1, IggVec2 *p2, IggVec2 *p3, IggPackedColor col);
extern void iggAddText(IggDrawList handle, IggVec2 const *pos, IggPackedColor col, const char *text, int length);
extern void iggAddImage(IggDrawList handle, IggTextureID textureID, IggVec2* pMin, IggVec2* pMax);

extern void iggAddBezierCubic(IggDrawList handle, IggVec2 *pos0,
                                      IggVec2 *cp0, IggVec2 *cp1, IggVec2 *pos1,
                                      IggPackedColor col, float thickness,
                                      int num_segments);

extern void iggAddQuad(IggDrawList handle, IggVec2 *p1, IggVec2 *p2,
                               IggVec2 *p3, IggVec2 *p4, IggPackedColor col,
                               float thickness);
extern void iggAddQuadFilled(IggDrawList handle, IggVec2 *p1,
                                     IggVec2 *p2, IggVec2 *p3, IggVec2 *p4,
                                     IggPackedColor col);

extern void iggPathClear(IggDrawList handle);
extern void iggPathLineTo(IggDrawList handle, IggVec2 *pos);
extern void iggPathLineToMergeDuplicate(IggDrawList handle,
                                                IggVec2 *pos);
extern void iggPathFillConvex(IggDrawList handle, IggPackedColor col);
extern void iggPathStroke(IggDrawList handle, IggPackedColor col,
                                  IggBool closed, float thickness);
extern void iggPathArcTo(IggDrawList handle, IggVec2 *center,
                                 float radius, float a_min, float a_max,
                                 int num_segments);
extern void iggPathArcToFast(IggDrawList handle, IggVec2 *center,
                                     float radius, int a_min_of_12,
                                     int a_max_of_12);
extern void iggPathBezierCubicCurveTo(IggDrawList handle, IggVec2 *p1,
                                         IggVec2 *p2, IggVec2 *p3,
                                         int num_segments);

extern void iggAddImageV(IggDrawList handle, IggTextureID id,
                                IggVec2 *p_min, IggVec2 *p_max,
                                IggVec2 *uv_min, IggVec2 *uv_max,
                                IggPackedColor color);


extern void iggPushClipRect(IggDrawList handle, IggVec2 const *min, IggVec2 const *max, IggBool intersectWithCurrentClipRect);
extern void iggPopClipRect(IggDrawList handle);

extern IggDrawList iggGetWindowDrawList();
extern IggDrawList iggGetBackgroundDrawList();

#ifdef __cplusplus
}
#endif
