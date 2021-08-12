#include "ConfiguredImGui.h"

#include "DrawList.h"
#include "WrapperConverter.h"

int iggDrawListGetCommandCount(IggDrawList handle)
{
   ImDrawList *list = reinterpret_cast<ImDrawList *>(handle);
   return list->CmdBuffer.Size;
}

IggDrawCmd iggDrawListGetCommand(IggDrawList handle, int index)
{
   ImDrawList *list = reinterpret_cast<ImDrawList *>(handle);
   return reinterpret_cast<IggDrawCmd>(&list->CmdBuffer.Data[index]);
}

void iggDrawListGetRawIndexBuffer(IggDrawList handle, void **data, int *byteSize)
{
   ImDrawList *list = reinterpret_cast<ImDrawList *>(handle);
   *data = list->IdxBuffer.Data;
   *byteSize = static_cast<int>(sizeof(ImDrawIdx)) * list->IdxBuffer.Size;
}

void iggDrawListGetRawVertexBuffer(IggDrawList handle, void **data, int *byteSize)
{
   ImDrawList *list = reinterpret_cast<ImDrawList *>(handle);
   *data = list->VtxBuffer.Data;
   *byteSize = static_cast<int>(sizeof(ImDrawVert)) * list->VtxBuffer.Size;
}

void iggGetIndexBufferLayout(size_t *entrySize)
{
   *entrySize = sizeof(ImDrawIdx);
}

void iggGetVertexBufferLayout(size_t *entrySize, size_t *posOffset, size_t *uvOffset, size_t *colOffset)
{
   *entrySize = sizeof(ImDrawVert);
   *posOffset = IM_OFFSETOF(ImDrawVert, pos);
   *uvOffset = IM_OFFSETOF(ImDrawVert, uv);
   *colOffset = IM_OFFSETOF(ImDrawVert, col);
}

void iggAddLine(IggDrawList handle, IggVec2 const *p1, IggVec2 const *p2, IggPackedColor col, float thickness)
{
   Vec2Wrapper p1Arg(p1);
   Vec2Wrapper p2Arg(p2);

   ImDrawList *list = reinterpret_cast<ImDrawList *>(handle);
   list->AddLine(*p1Arg, *p2Arg, col, thickness);
}

void iggAddRect(IggDrawList handle, IggVec2 const *min, IggVec2 const *max, IggPackedColor col, float rounding, int flags, float thickness)
{
   Vec2Wrapper minArg(min);
   Vec2Wrapper maxArg(max);

   ImDrawList *list = reinterpret_cast<ImDrawList *>(handle);
   list->AddRect(*minArg, *maxArg, col, rounding, flags, thickness);
}

void iggAddRectFilled(IggDrawList handle, IggVec2 const *min, IggVec2 const *max, IggPackedColor col, float rounding, int flags)
{
   Vec2Wrapper minArg(min);
   Vec2Wrapper maxArg(max);

   ImDrawList *list = reinterpret_cast<ImDrawList *>(handle);
   list->AddRectFilled(*minArg, *maxArg, col, rounding, flags);
}

void iggAddCircle(IggDrawList handle, IggVec2 const *center, float radius, IggPackedColor col, int numSegments, float thickness)
{
   Vec2Wrapper centerArg(center);

   ImDrawList *list = reinterpret_cast<ImDrawList *>(handle);
   list->AddCircle(*centerArg, radius, col, numSegments, thickness);
}

void iggAddCircleFilled(IggDrawList handle, IggVec2 const *center, float radius, IggPackedColor col, int numSegments)
{
   Vec2Wrapper centerArg(center);

   ImDrawList *list = reinterpret_cast<ImDrawList *>(handle);
   list->AddCircleFilled(*centerArg, radius, col, numSegments);
}

void iggAddTriangle(IggDrawList handle, IggVec2 *p1, IggVec2 *p2, IggVec2 *p3, IggPackedColor col, float thickness)
{
   Vec2Wrapper p1Arg(p1);
   Vec2Wrapper p2Arg(p2);
   Vec2Wrapper p3Arg(p3);

   ImDrawList *list = reinterpret_cast<ImDrawList *>(handle);
   list->AddTriangle(*p1Arg, *p2Arg, *p3Arg, col, thickness);
}

void iggAddTriangleFilled(IggDrawList handle, IggVec2 *p1, IggVec2 *p2, IggVec2 *p3, IggPackedColor col)
{
   Vec2Wrapper p1Arg(p1);
   Vec2Wrapper p2Arg(p2);
   Vec2Wrapper p3Arg(p3);

   ImDrawList *list = reinterpret_cast<ImDrawList *>(handle);
   list->AddTriangleFilled(*p1Arg, *p2Arg, *p3Arg, col);
}

void iggAddText(IggDrawList handle, IggVec2 const *pos, IggPackedColor col, const char *text, int length)
{
   Vec2Wrapper posArg(pos);
   ImDrawList *list = reinterpret_cast<ImDrawList *>(handle);
   list->AddText(*posArg, col, text, text + length);
}


void iggAddBezierCubic(IggDrawList handle, IggVec2 *pos0, IggVec2 *cp0,
                               IggVec2 *cp1, IggVec2 *pos1, unsigned int col,
                               float thickness, int num_segments) {
  ImDrawList *list = reinterpret_cast<ImDrawList *>(handle);
  Vec2Wrapper pos0Arg(pos0);
  Vec2Wrapper pos1Arg(pos1);
  Vec2Wrapper cp0Arg(cp0);
  Vec2Wrapper cp1Arg(cp1);
  list->AddBezierCubic(*pos0Arg, *cp0Arg, *cp1Arg, *pos1Arg, col, thickness,
                       num_segments);
}

void iggAddQuad(IggDrawList handle, IggVec2 *p1, IggVec2 *p2,
                        IggVec2 *p3, IggVec2 *p4, IggPackedColor col,
                        float thickness) {
  ImDrawList *list = reinterpret_cast<ImDrawList *>(handle);
  Vec2Wrapper p1Arg(p1);
  Vec2Wrapper p2Arg(p2);
  Vec2Wrapper p3Arg(p3);
  Vec2Wrapper p4Arg(p4);
  list->AddQuad(*p1Arg, *p2Arg, *p3Arg, *p4Arg, col, thickness);
}

void iggAddQuadFilled(IggDrawList handle, IggVec2 *p1, IggVec2 *p2,
                              IggVec2 *p3, IggVec2 *p4, IggPackedColor col) {
  ImDrawList *list = reinterpret_cast<ImDrawList *>(handle);
  Vec2Wrapper p1Arg(p1);
  Vec2Wrapper p2Arg(p2);
  Vec2Wrapper p3Arg(p3);
  Vec2Wrapper p4Arg(p4);
  list->AddQuadFilled(*p1Arg, *p2Arg, *p3Arg, *p4Arg, col);
}

void iggPathClear(IggDrawList handle) {
  ImDrawList *list = reinterpret_cast<ImDrawList *>(handle);
  list->PathClear();
}

void iggPathLineTo(IggDrawList handle, IggVec2 *pos) {
  ImDrawList *list = reinterpret_cast<ImDrawList *>(handle);
  Vec2Wrapper posArg(pos);
  list->PathLineTo(*posArg);
}

void iggPathLineToMergeDuplicate(IggDrawList handle, IggVec2 *pos) {
  ImDrawList *list = reinterpret_cast<ImDrawList *>(handle);
  Vec2Wrapper posArg(pos);
  list->PathLineToMergeDuplicate(*posArg);
}

void iggPathFillConvex(IggDrawList handle, IggPackedColor col) {
  ImDrawList *list = reinterpret_cast<ImDrawList *>(handle);
  list->PathFillConvex(col);
}

void iggPathStroke(IggDrawList handle, IggPackedColor col, IggBool closed,
                           float thickness) {
  ImDrawList *list = reinterpret_cast<ImDrawList *>(handle);
  list->PathStroke(col, closed != 0, thickness);
}

void iggPathArcTo(IggDrawList handle, IggVec2 *center, float radius,
                          float a_min, float a_max, int num_segments) {
  ImDrawList *list = reinterpret_cast<ImDrawList *>(handle);
  Vec2Wrapper centerArg(center);
  list->PathArcTo(*centerArg, radius, a_min, a_max, num_segments);
}

void iggPathArcToFast(IggDrawList handle, IggVec2 *center, float radius,
                              int a_min_of_12, int a_max_of_12) {
  ImDrawList *list = reinterpret_cast<ImDrawList *>(handle);
  Vec2Wrapper centerArg(center);
  list->PathArcToFast(*centerArg, radius, a_min_of_12, a_max_of_12);
}

void iggPathBezierCubicCurveTo(IggDrawList handle, IggVec2 *p1, IggVec2 *p2,
                                  IggVec2 *p3, int num_segments) {
  ImDrawList *list = reinterpret_cast<ImDrawList *>(handle);
  Vec2Wrapper p1Arg(p1);
  Vec2Wrapper p2Arg(p2);
  Vec2Wrapper p3Arg(p3);
  list->PathBezierCubicCurveTo(*p1Arg, *p2Arg, *p3Arg, num_segments);
}

void iggAddImage(IggDrawList handle, IggTextureID id, IggVec2 *p_min,
                         IggVec2 *p_max) {
  ImDrawList *list = reinterpret_cast<ImDrawList *>(handle);
  Vec2Wrapper pMinArg(p_min);
  Vec2Wrapper pMaxArg(p_max);
  list->AddImage(ImTextureID(id), *pMinArg, *pMaxArg);
}

void iggAddImageV(IggDrawList handle, IggTextureID textureID, IggVec2* pMin, IggVec2* pMax, IggVec2* uvMin, IggVec2* uvMax, IggPackedColor col) {
  Vec2Wrapper pMinArg(pMin);
  Vec2Wrapper pMaxArg(pMax);
  Vec2Wrapper uvMinArg(uvMin);
  Vec2Wrapper uvMaxArg(uvMax);

  ImDrawList* list = reinterpret_cast<ImDrawList *>(handle);
  list->AddImage(reinterpret_cast<ImTextureID>(textureID), *pMinArg, *pMaxArg, *uvMinArg, *uvMaxArg, col);
}

void iggPushClipRect(IggDrawList handle, IggVec2 const *min, IggVec2 const *max, IggBool intersectWithCurrentClipRect)
{
   ImDrawList *list = reinterpret_cast<ImDrawList *>(handle);
   Vec2Wrapper minArg(min);
   Vec2Wrapper maxArg(max);
   list->PushClipRect(*minArg, *maxArg, intersectWithCurrentClipRect != 0);
}

void iggPopClipRect(IggDrawList handle)
{
   ImDrawList *list = reinterpret_cast<ImDrawList *>(handle);
   list->PopClipRect();
}

IggDrawList iggGetWindowDrawList()
{
   return static_cast<IggDrawList>(const_cast<ImDrawList *>(ImGui::GetWindowDrawList()));
}

IggDrawList iggGetBackgroundDrawList()
{
   return static_cast<IggDrawList>(const_cast<ImDrawList *>(ImGui::GetBackgroundDrawList()));
}
