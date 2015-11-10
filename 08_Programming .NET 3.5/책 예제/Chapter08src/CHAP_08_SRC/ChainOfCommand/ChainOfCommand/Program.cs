using System;

namespace ChainOfCommand
{
    class Program
    {

        static void Main()
        {
            Request request;

            // Setup Chain of Responsibility
            Approver Buzz = new Pilot();
            Approver Neil = new Commander();
            Approver Gene = new FlightDirector();

            Buzz.Successor = Neil;
            Neil.Successor = Gene;

            // Generate and process launch requests
            request = new Request(2, 35000.00, "Launch 1");
            Buzz.ProcessRequest(request);

            request = new Request(3, 35000.00, "Launch 2");
            Buzz.ProcessRequest(request);

            request = new Request(3, 1221000.50, "Launch 3");
            Buzz.ProcessRequest(request);

            // Wait for user
            Console.Read();
        }
    }

    public class LaunchRequestEventArgs : EventArgs
    {
 
        // Properties
        public int Crew                 { get; set; }
        public string LaunchCommand     { get; set; }
        public double FuelOnBoardInLbs  { get; set; }

        // Constructor
        public LaunchRequestEventArgs(
            int crewCount, 
            double fuelOnBoard,
            string launchCommandRequest)
        {
            this.Crew = crewCount;
            this.FuelOnBoardInLbs = fuelOnBoard;
            this.LaunchCommand = launchCommandRequest;
        }

    }

    // Generic delegate for hooking up launch requests
    public delegate void LaunchRequestEventHandler<T, U>(T sender, U eventArgs);

    // "Handler"
    abstract class Approver
    {
        public Approver Successor { get;  set; }

        // Event
        public event LaunchRequestEventHandler<Approver, LaunchRequestEventArgs> Request;

        // Invoke the launch Request event
        public virtual void OnRequest(LaunchRequestEventArgs e)
        {
            if (Request != null)
            {
                Request(this, e);
            }
        }

        public void ProcessRequest(Request request)
        {
            OnRequest(new LaunchRequestEventArgs(
                request.Crew, request.FuelOnBoardInLbs, request.LaunchCommand));
        }


    }

    // "ConcreteHandler"

    class Pilot : Approver
    {
        // Constructor
        public Pilot()
        {
            // Hook up delegate to event
            this.Request += new LaunchRequestEventHandler<Approver, LaunchRequestEventArgs>(PilotRequest);
        }

        public void PilotRequest(Approver approver, LaunchRequestEventArgs e)
        {
            if (e.Crew < 3)
            {
                Console.WriteLine("{0}, you are only reporting {1} crew on board.",
                    this.GetType().Name, e.Crew);
                Console.WriteLine("We need at least 3. {0} denied.\n\n", e.LaunchCommand);
                    
            }
            else if (Successor != null)
            {
                Console.WriteLine("{0}: Commander says: {1} Go.\n\n", e.LaunchCommand, this.GetType().Name);
                Successor.OnRequest(e);
            }
        }
    }

    // "ConcreteHandler"
    class Commander : Approver
    {
        // Constructor
        public Commander()
        {
            // Hook up delegate to event
            this.Request +=
                new LaunchRequestEventHandler<Approver, LaunchRequestEventArgs>(CommanderRequest);
        }

        public void CommanderRequest(Approver approver,
            LaunchRequestEventArgs e)
        {
                if (e.FuelOnBoardInLbs < 1000000.0)
                {
                    Console.WriteLine("{0}, you are only reporting {1} lbs of fuel on board.",
                        this.GetType().Name, e.FuelOnBoardInLbs);
                    Console.WriteLine("You need at least 1 Million. {0} denied.\n\n", e.LaunchCommand);
                        
                }
                else if (Successor != null)
                {
                    Console.WriteLine("{0}: Flight Director says: {1} Go.\n\n",e.LaunchCommand, this.GetType().Name);
                    Successor.OnRequest(e);
                }
            
        }
    }

    // "ConcreteHandler"
    class FlightDirector : Approver
    {
        // Constructor
        public FlightDirector()
        {
            // Hook up delegate to event
            this.Request +=
                new LaunchRequestEventHandler<Approver, LaunchRequestEventArgs>(FlightDirectorRequest);
        }

        public void FlightDirectorRequest(Approver approver, LaunchRequestEventArgs e)
        {
            if (e.FuelOnBoardInLbs < 1000000.0)
            {
                Console.WriteLine("{0}, you are only reporting {1} lbs of fuel on board.",
                    this.GetType().Name, e.FuelOnBoardInLbs);
                Console.WriteLine("You need at least 1 Million. {0} Denied.\n\n", e.LaunchCommand);

            }
            else
            {
                Console.WriteLine(
                    "{0}: All Systems Go! Launch Control, launch is a Go!",
                    this.GetType().Name);
            }
        }
    }

    // Request details

    class Request
    {
        private int crew;
        private double fuelOnBoardInLbs;
        private string launchCommand;

        // Constructor
        public Request(int crewCount, double fuelOnBoard,string launchCommandRequest)
        {
            this.crew = crewCount;
            this.fuelOnBoardInLbs = fuelOnBoard;
            this.launchCommand = launchCommandRequest;
        }

        // Properties
        public int Crew
        {
            get { return crew; }
            set { crew = value; }
        }

        public string LaunchCommand
        {
            get { return launchCommand; }
            set { launchCommand = value; }
        }

        public double FuelOnBoardInLbs
        {
            get { return fuelOnBoardInLbs; }
            set { fuelOnBoardInLbs = value; }
        }
    }
}
