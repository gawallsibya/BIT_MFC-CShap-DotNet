using System;
using System.Collections.Generic;
using System.Text;
using System.Windows;

namespace DependencyPropertyDemo
{
    // DependencyProperty 정의

    public class Animal : DependencyObject
    {
        public static readonly DependencyProperty AniNameProperty =
        DependencyProperty.Register(
                "AniName", typeof(String), typeof(Animal),
                        new PropertyMetadata("Tiger"));

        public string AniName
        {
            get { return (string)GetValue(AniNameProperty); }
            set { SetValue(AniNameProperty, value); }
        }

    }


    //public class Animal
    //{
    //    private string aniName = "Tiger";

    //    public string AniName
    //    {
    //        get { return aniName; }
    //        set { aniName = value; }
    //    }
    //}

    //public class AnotherAnimal : DependencyObject
    //{
    //    public static readonly DependencyProperty AniNameProperty =
    //             Animal.AniNameProperty.AddOwner(typeof(AnotherAnimal),
    //             new PropertyMetadata("AnotherAnimal"));

    //    public string AniName
    //    {
    //        get { return (string)GetValue(AniNameProperty); }
    //        set { SetValue(AniNameProperty, value); }
    //    }
    //}



}
