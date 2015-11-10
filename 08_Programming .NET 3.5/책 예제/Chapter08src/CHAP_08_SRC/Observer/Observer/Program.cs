using System;

namespace Observer
{
    class Program
    {

        static void Main()
        {
            DateTime now = DateTime.Now;
            // Create new flights with a departure time and add from and to destinations
            CarrierSchedule jetBlue = new CarrierSchedule("JetBlue", now);
            jetBlue.Attach(new AirTrafficControl("Boston"));
            jetBlue.Attach(new AirTrafficControl("Seattle"));

            // ATCs will be notified of delays in departure time
            jetBlue.DepartureDateTime = 
                now.AddHours(1.25); // weather delay

            jetBlue.DepartureDateTime = 
                now.AddHours(1.75); // weather got worse

            jetBlue.DepartureDateTime = 
                now.AddHours(0.5);  // security delay

            jetBlue.DepartureDateTime = 
                now.AddHours(0.75); // Seattle puts a ground stop in place

            // Wait for user
            Console.Read();
        }
    }

    // Generic delegate type for hooking up flight schedule requests
    public delegate void ChangeEventHandler<T,U>
        (T sender, U eventArgs);

    // Customize event arguments to fit the activity
    public class ChangeEventArgs : EventArgs 
    {
        public ChangeEventArgs(string name, string outAirport, string inAirport, DateTime leaves) 
        {
            this.Airline = name;
            this.DeparturnAirport = outAirport;
            this.ArrivalAirport = inAirport;
            this.DepartureDateTime = leaves;
        }

        // Our Properties
        public string Airline               { get; set; }
        public string DeparturnAirport      { get; set; }
        public string ArrivalAirport        { get; set; }
        public DateTime DepartureDateTime   { get; set; }

    }  

    // Subject: This is the thing being watched by Air Traffic Control centers
    abstract class AirlineSchedule
    {

        // properties 
        public string Name                  { get; set; }
        public string DeparturnAirport      { get; set; }
        public string ArrivalAirport        { get; set; }
        private DateTime departureDateTime;

        public AirlineSchedule(string airline, string outAirport, string inAirport, DateTime leaves)
        {
            this.Name = airline;
            this.DeparturnAirport = outAirport;
            this.ArrivalAirport = inAirport;
            this.DepartureDateTime = leaves;
        }

        // Event
        public event ChangeEventHandler<AirlineSchedule, ChangeEventArgs> Change;
        
        // Invoke the Change event
        public virtual void OnChange(ChangeEventArgs e) 
        {
            if (Change != null)
            {
                Change(this, e);
            }
        }

        // Here is where we actually attach our observers (ATCs)
        public void Attach(AirTrafficControl airTrafficControl)
        {
            Change += 
                new ChangeEventHandler<AirlineSchedule, ChangeEventArgs>
                    (airTrafficControl.Update);
        }

        public void Detach(AirTrafficControl airTrafficControl)
        {
            Change -= new ChangeEventHandler<AirlineSchedule, ChangeEventArgs>
                (airTrafficControl.Update);
        }


        public DateTime DepartureDateTime
        {
            get { return departureDateTime; }
            set
            {
                departureDateTime = value;
                OnChange(new ChangeEventArgs(
                    this.Name, 
                    this.DeparturnAirport,
                    this.ArrivalAirport,
                    this.departureDateTime));
                Console.WriteLine("");
            }
        }


    }

    // A Concrete Subject
    class CarrierSchedule : AirlineSchedule
    {
        // Jesse and Alex only really ever need to fly to one place...
        public CarrierSchedule(string name, DateTime departing): 
            base(name,"Boston", "Seattle", departing)
        {
        }
    }

    // An Observer
    interface IATC
    {
        void Update(AirlineSchedule sender, ChangeEventArgs e);
    }

    // The Concrete Observer
    class AirTrafficControl : IATC
    {
        public string Name { get; set; }

        // Constructor
        public AirTrafficControl(string name)
        {
             this.Name = name;
        }

        public void Update(AirlineSchedule sender, ChangeEventArgs e)
        {

            Console.WriteLine(
                "{0} Air Traffic Control Notified:\n {1}'s flight 497 from {2} " +
                "to {3} new deprture time: {4:hh:mmtt}", 
                Name, 
                e.Airline, 
                e.DeparturnAirport, 
                e.ArrivalAirport, 
                e.DepartureDateTime);
            Console.WriteLine("---------");
        }
        public CarrierSchedule CarrierSchedule { get; set; }
    }
}

