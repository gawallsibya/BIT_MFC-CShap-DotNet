﻿using System;
using System.Collections.Generic;
using System.Text;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Shapes;
using System.Windows.Xps.Packaging;

namespace WPFControls
{
    /// <summary>
    /// FlowDocumentReader.xaml에 대한 상호 작용 논리
    /// </summary>
    public partial class FlowDocumentReader : Window
    {
        public FlowDocumentReader()
        {
            InitializeComponent();
            Loaded += new RoutedEventHandler(FlowDocumentReader_Loaded);
        }

        void FlowDocumentReader_Loaded(object sender, RoutedEventArgs e)
        {

        }
    }
}
