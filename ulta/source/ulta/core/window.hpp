#pragma once

namespace ulta
{
    class window
    {
        public:
            window() = default;
            virtual ~window() = default;

            virtual void on_update() = 0;


        private:
    };
}