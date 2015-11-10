using System;
using System.Collections.Generic;
using System.Text;
using System.Windows.Documents;
using System.Windows.Controls;

namespace BasicElementDemo
{
    class Demo
    {
        FlowDocument fd;

        public FlowDocument Fd
        {
            get { return fd; }
            set { fd = value; }
        }
        FlowDocumentReader fr;

        public FlowDocumentReader Fr
        {
            get { return fr; }
            set { fr = value; }
        }
    }
}
