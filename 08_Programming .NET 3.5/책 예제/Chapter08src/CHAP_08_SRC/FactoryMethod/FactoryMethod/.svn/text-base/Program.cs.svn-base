using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace FactoryMethod
{


    class Program
    {


        static void Main()
        {
            // Note: document constructors call Factory Method
            List<Car> cars = new List<Car>();
            cars.Add(new CooperMini());
            cars.Add(new BMWSedan());
            cars.Add(new Prius());
            cars.Add(new FordExpedition());

            // Display document pages
            foreach (Car car in cars)
            {
                Console.WriteLine(car + " fully loaded with these features:");
                foreach (Feature feature in car.Features)
                {
                    Console.WriteLine(" " + feature);
                }
                Console.WriteLine();
            }

            // Wait for user
            Console.Read();
        }
    }

    // "Product"

    abstract class Feature
    {
        // Override. Display class name
        public override string ToString()
        {
            return this.GetType().Name;
        }
    }

    // "ConcreteProduct"
    class FourWheels : Feature
    {
    }

    // "ConcreteProduct"

    class V6Engine : Feature
    {
    }

    // "ConcreteProduct"

    class V8Engine : Feature
    {
    }

    // "ConcreteProduct"

    class FourDoors : Feature
    {
    }

    // "ConcreteProduct"

    class TwoDoors : Feature
    {
    }

    // "ConcreteProduct"

    class SunRoof : Feature
    {
    }

    // "ConcreteProduct"

    class AirBags : Feature
    {
    }

    // "ConcreteProduct"

    class HybridEngine : Feature
    {
    }

    // "Creator"

    abstract class Car
    {
        private List<Feature> features = new List<Feature>();

        // Constructor invokes Factory Method
        public Car()
        {
            this.CreateFeatures();
        }

        // Property
        public List<Feature> Features
        {
            get { return features; }
        }

        // Factory Method
        public abstract void CreateFeatures();

        // Override
        public override string ToString()
        {
            return this.GetType().Name;
        }
    }

    // "ConcreteCreator"

    class CooperMini : Car
    {
        // Factory Method implementation
        public override void CreateFeatures()
        {
            Features.Add(new FourWheels());
            Features.Add(new TwoDoors());
            Features.Add(new AirBags());
            Features.Add(new V6Engine());
            Features.Add(new SunRoof());
        }
    }

    // "ConcreteCreator"
    class BMWSedan : Car
    {
        // Factory Method implementation
        public override void CreateFeatures()
        {
            Features.Add(new FourDoors());
            Features.Add(new FourWheels());
            Features.Add(new AirBags());
            Features.Add(new V8Engine());
            Features.Add(new SunRoof());
        }
    }

    class Prius : Car
    {
        // Factory Method implementation
        public override void CreateFeatures()
        {
            Features.Add(new TwoDoors());
            Features.Add(new FourWheels());
            Features.Add(new HybridEngine());
            Features.Add(new AirBags());
            Features.Add(new SunRoof());
        }
    }

    class FordExpedition : Car
    {
        // Factory Method implementation
        public override void CreateFeatures()
        {
            Features.Add(new FourDoors());
            Features.Add(new FourWheels());
            Features.Add(new V8Engine());
            Features.Add(new AirBags());
        }
    }
}



