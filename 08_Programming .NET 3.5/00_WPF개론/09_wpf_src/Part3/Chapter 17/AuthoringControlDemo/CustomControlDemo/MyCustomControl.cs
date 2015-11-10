using System;
using System.Collections.Generic;
using System.Text;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace CustomControlDemo
{
    /// <summary>
    /// XAML 파일에서 이 사용자 지정 컨트롤을 사용하려면 1a 또는 1b단계를 수행한 다음 2단계를 수행하십시오.
    ///
    /// 1a단계) 현재 프로젝트에 있는 XAML 파일에서 이 사용자 지정 컨트롤 사용.
    /// 이 XmlNamespace 특성을 사용할 마크업 파일의 루트 요소에 이 특성을 
    /// 추가합니다.
    ///
    ///     xmlns:MyNamespace="clr-namespace:CustomControlDemo"
    ///
    ///
    /// 1b단계) 다른 프로젝트에 있는 XAML 파일에서 이 사용자 지정 컨트롤 사용.
    /// 이 XmlNamespace 특성을 사용할 마크업 파일의 루트 요소에 이 특성을 
    /// 추가합니다.
    ///
    ///     xmlns:MyNamespace="clr-namespace:CustomControlDemo;assembly=CustomControlDemo"
    ///
    /// 또한 XAML 파일이 있는 프로젝트의 프로젝트 참조를 이 프로젝트에 추가하고
    /// 다시 빌드하여 컴파일 오류를 방지해야 합니다.
    ///
    ///     솔루션 탐색기에서 대상 프로젝트를 마우스 오른쪽 단추로 클릭하고
    ///     [참조 추가]->[프로젝트]를 차례로 클릭한 다음 이 프로젝트를 선택합니다.
    ///
    ///
    /// 2단계)
    /// 계속 진행하여 XAML 파일에서 컨트롤을 사용합니다.
    ///
    ///     <MyNamespace:CustomControl1/>
    ///
    /// </summary>
    public partial class MyCustomControl : Control
    {
      
        public MyCustomControl()
        {
            InitializeCommands();
        }

        static MyCustomControl()
        {
            DefaultStyleKeyProperty.OverrideMetadata(typeof(MyCustomControl),
                new FrameworkPropertyMetadata(typeof(MyCustomControl)));
        }

      
        public decimal Value
        {
            get { return (decimal)GetValue(ValueProperty); }
            set { SetValue(ValueProperty, value); }
        }

        
        public static readonly DependencyProperty ValueProperty =
            DependencyProperty.Register(
                "Value", typeof(decimal), typeof(MyCustomControl),
                new FrameworkPropertyMetadata(MinValue, new PropertyChangedCallback(OnValueChanged),
                                              new CoerceValueCallback(CoerceValue)));

        private static object CoerceValue(DependencyObject element, object value)
        {
            decimal newValue = (decimal)value;
            MyCustomControl control = (MyCustomControl)element;

            newValue = Math.Max(MinValue, Math.Min(MaxValue, newValue));

            return newValue;
        }

        private static void OnValueChanged(DependencyObject obj, DependencyPropertyChangedEventArgs args)
        {
            MyCustomControl control = (MyCustomControl)obj;

            RoutedPropertyChangedEventArgs<decimal> e = new RoutedPropertyChangedEventArgs<decimal>(
                (decimal)args.OldValue, (decimal)args.NewValue, ValueChangedEvent);
            control.OnValueChanged(e);
        }
        
        public static readonly RoutedEvent ValueChangedEvent = EventManager.RegisterRoutedEvent(
            "ValueChanged", RoutingStrategy.Bubble,
            typeof(RoutedPropertyChangedEventHandler<decimal>), typeof(MyCustomControl));

       
        public event RoutedPropertyChangedEventHandler<decimal> ValueChanged
        {
            add { AddHandler(ValueChangedEvent, value); }
            remove { RemoveHandler(ValueChangedEvent, value); }
        }
      
        protected virtual void OnValueChanged(RoutedPropertyChangedEventArgs<decimal> args)
        {
            RaiseEvent(args);
        }

        #region Commands

        public static RoutedCommand IncreaseCommand
        {
            get
            {
                return _increaseCommand;
            }
        }
        public static RoutedCommand DecreaseCommand
        {
            get
            {
                return _decreaseCommand;
            }
        }

        private static void InitializeCommands()
        {
            _increaseCommand = new RoutedCommand("IncreaseCommand", typeof(MyCustomControl));
            CommandManager.RegisterClassCommandBinding(typeof(MyCustomControl), new CommandBinding(_increaseCommand, OnIncreaseCommand));
            CommandManager.RegisterClassInputBinding(typeof(MyCustomControl), new InputBinding(_increaseCommand, new KeyGesture(Key.Up)));

            _decreaseCommand = new RoutedCommand("DecreaseCommand", typeof(MyCustomControl));
            CommandManager.RegisterClassCommandBinding(typeof(MyCustomControl), new CommandBinding(_decreaseCommand, OnDecreaseCommand));
            CommandManager.RegisterClassInputBinding(typeof(MyCustomControl), new InputBinding(_decreaseCommand, new KeyGesture(Key.Down)));
        }

        private static void OnIncreaseCommand(object sender, ExecutedRoutedEventArgs e)
        {
            MyCustomControl control = sender as MyCustomControl;
            if (control != null)
            {
                control.OnIncrease();
            }
        }
        private static void OnDecreaseCommand(object sender, ExecutedRoutedEventArgs e)
        {
            MyCustomControl control = sender as MyCustomControl;
            if (control != null)
            {
                control.OnDecrease();
            }
        }

        protected virtual void OnIncrease()
        {
            Value++;
        }
        protected virtual void OnDecrease()
        {
            Value--;
        }

       private static RoutedCommand _increaseCommand;
       private static RoutedCommand _decreaseCommand;

        #endregion

        private const decimal MinValue = 0, MaxValue = 100;
    }

}
