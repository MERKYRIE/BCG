#pragma once

namespace NBCG
{
    inline class CVertexBufferObject
    {
        private:
            unsigned int PIdentifier;
        public:
            CVertexBufferObject();
            CVertexBufferObject& MBind();
            CVertexBufferObject& MBuffer();
    }
    GVertexBufferObject;
}