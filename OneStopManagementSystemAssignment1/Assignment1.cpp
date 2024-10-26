// Data Structures (CS-2001) Assignment#1 
// "One-Stop Management System Using Linear Data Structures" 
// Objective: The objective of this assignment is to build a One-Stop Management System that uses linear data structures 
// such as arrays, linked lists, stacks, and queues. This system will help manage student service requests, agents, and 
// service logs. 
// Overview: 
// In this assignment, students will create a simplified One-Stop system where they can: Add, remove, 
// and search for service requests (tickets). 
// Manage support agents (one each for IT, admin, accounts, and 3 for academics) and assign them tickets. 
// Track ticket resolution and response logs using stacks and queues. 
// Sort tickets based on priority, creation time, or agent assignment using different sorting algorithms. 
// Generate reports and analyze system performance based on response times. Requirements: 
// 1. Service Request (Ticket) Management 
// You need to implement a data structure to manage service requests (tickets). 
// Each ticket will have the following attributes: 
// Ticket ID (int) 
// Customer Name (String) 
// Priority (int) (1 = High, 2 = Medium, 3 = Low) 
// Service Request description (String) 
// Creation Time (timestamp) 
// Status (open/closed) 
// Ticket close time: When the ticket is finally closed (timestamp) 
// Features to Implement: 
// 1. Add a Ticket: Add a new support ticket to the system. 
// 2. Remove a Ticket: Remove a ticket from the system using its Ticket ID. 
// 3. Search for a Ticket: Search for a ticket by Ticket ID or by the customer’s name. 
// 4. Sort Tickets: Implement sorting algorithms to sort tickets based on the attributes below. 
// Users will be presented a choice about which sorting algorithm they want to use: Priority 
// Creation Time 
// Customer Name 
// Data Structure Choices: 
// Use a Linked List to manage tickets.
// 2. Agent Management 
// Each support agent will have the following attributes: 
// Agent ID (int) 
// Name (String) 
// Assigned Tickets (List of Ticket IDs) 
// Availability (boolean) 
// Features to Implement: 
// 1. Add an Agent: Add a new support agent to the system. 
// 2. Assign Ticket to Agent: Automatically assign open tickets to available agents based on the following conditions: 
// 3. Agents should be assigned high-priority tickets first. 
// 4. Agents with fewer open tickets should be assigned new tickets first. 
// 5. Mark Agent Unavailable: After an agent is assigned a ticket, 
//         mark them as unavailable if they are at full capacity (e.g., max 5 open tickets). 
// 6. Status (String): Available/ Unavailable 
// Data Structure Choices: 
// Use a Dynamic Array to manage agents. 
// 3. Ticket Resolution Logs (Transaction Log) 
// To track the One-Stop’s ticket transactions, implement a log system using Stacks and Queues: 
// 1. Ticket Resolution Log (Stack): Maintain a stack of the most recent ticket resolution operations.
//      Every time a ticket is closed, log the transaction into the stack. 
// 2. Pending Ticket Queue: Maintain a queue of tickets waiting for agent assignment (FIFO structure). 
//     This queue should handle all incoming tickets based on their priority and creation time. 
// 3. Log Closed Ticket: When a ticket is resolved (marked as closed), log the transaction into the resolution stack. 
// 4. Add Ticket to Pending Queue: All incoming tickets (based on priority) will be placed in the pending ticket queue
//      until an agent is available to handle them. 
// 5. View Logs: Display the most recent ticket resolution logs. 
// Data Structure Choices: 
// Stacks and Queues 
// 4. Reporting and Analytics 
// Create the following reports using sorting and searching algorithms: 
// 1. List of Open Tickets: Search for open tickets using the searching algorithm 
//     Display all open tickets sorted by priority or creation time.
// 2. Agent Ticket Load: Display the list of agents and their currently assigned tickets.
//      Sort agents by the number of assigned tickets. 
// 3. Ticket Resolution History: Show the most recent ticket resolutions using the resolution log (stack). 
// Data Structures: 
// Queue for managing pending ticket assignments. 
// Stack for managing the resolution logs. 
// Sorting Algorithms: 
// Implement Elementary sorts (Bubble Sort, Insertion Sort, Selection Sort), Advanced sorts (Merge Sort and Quicksort) 
//     for sorting and interpolation sort and Bubble sort for searching. There should be a configuration file 
//     where the user can specify which sorting and searching algorithm will be used by default. 
//     When the items to be sorted are less than any threshold (decide the threshold yourselves), 
//     the configured elementary sorting algorithm should be used. Otherwise the configured Merge Sort or Quick Sort 
//     should be used when handling larger datasets. 
// Efficiency: 
// Analyze the time complexity of the operations for managing tickets, agents, and logs. Every operation needs to
//     have the time taken by that operation mentioned on the screen. 
// Deliverables: 
// Create a command-line or GUI interface that allows users to interact with the system 
//     (e.g., adding/removing tickets, assigning agents, closing tickets). 
//     Code: Well-documented source code with clear comments explaining the logic.



//GPT STEP BY STEP LOGIC

// ### 1. **Understand the Requirements and Structure**
//    - Familiarize yourself with the different parts of the assignment: service requests, agent management, ticket logs,
//      and reporting/analytics.
//    - Identify the main operations: adding, removing, searching, sorting, and logging tickets, along with agent management
//      and report generation.

// ### 2. **Set Up Project Environment**
//    - Decide whether to use a command-line or GUI interface.
//    - Set up your project files in Visual Studio (or your preferred IDE) and create a configuration file for setting
//      default sorting/searching algorithms.

// ### 3. **Plan Data Structures**
//    - **Linked List**: For managing tickets, as this allows flexible memory usage for add/remove operations.
//    - **Dynamic Array**: For agent management, enabling easy access and modification of agent lists.
//    - **Stack & Queue**: For logging and managing ticket resolutions and pending ticket queues, as these will follow
//      LIFO and FIFO principles.

// ### 4. **Start Implementing Core Classes**
//    - **Ticket Class**:
//      - Define attributes: `Ticket ID`, `Customer Name`, `Priority`, `Service Description`, `Creation Time`, `Status`,
//          and `Close Time`.
//      - Implement a constructor and methods for setting status, closing tickets, and updating attributes.

//    - **Agent Class**:
//      - Define attributes: `Agent ID`, `Name`, `Assigned Tickets (List)`, `Availability (boolean)`, and `Status`.
//      - Include methods for assigning tickets, setting availability, and checking load (assigned tickets).

//    - **Log Class (Stack & Queue)**:
//      - Use a stack for resolved ticket logs and a queue for pending tickets.
//      - Implement methods for adding to and retrieving from the stack and queue as needed.

// ### 5. **Implement Ticket Management**
//    - **Add Ticket**: Append tickets to your linked list.
//    - **Remove Ticket**: Delete tickets by Ticket ID.
//    - **Search Ticket**: Search by Ticket ID or customer name.
//    - **Sort Tickets**: Implement different sorting algorithms (Bubble, Insertion, Selection for small data; 
//         Merge and Quicksort for large data).
//    - Use conditions for priority and creation time as defined.

// ### 6. **Agent Management**
//    - **Add Agent**: Create and store agents in a dynamic array.
//    - **Assign Ticket**: Sort agents by ticket load and assign high-priority tickets first. Implement availability 
//         checks based on ticket load.
//    - **Update Availability**: Mark agents unavailable when they reach max capacity, and update dynamically.

// ### 7. **Implement Ticket Resolution Log System**
//    - **Ticket Resolution Log (Stack)**: Every time a ticket is closed, push it onto the stack.
//    - **Pending Ticket Queue**: Add new tickets to the queue by priority and time until an agent is available.
//    - **Display Logs**: Show the most recent entries from the stack for easy access.

// ### 8. **Implement Sorting and Searching Algorithms**
//    - Develop basic and advanced sorting methods. Use a threshold to switch between elementary sorts (Bubble, Selection) 
//         and advanced sorts (Merge, Quick).
//    - Add searching methods, including interpolation search, for fast ticket and agent lookups.
//    - Implement configuration settings for the preferred sorting and searching methods.

// ### 9. **Create Reporting and Analytics Functions**
//    - **Open Tickets**: Retrieve and display open tickets sorted by priority or creation time.
//    - **Agent Ticket Load**: Show agents and their assigned ticket counts, sorted by load.
//    - **Ticket Resolution History**: Display recent resolutions from the resolution log stack.

// ### 10. **Implement Command-line or GUI Interface**
//    - Set up input and output handling so users can add, remove, search, and assign tickets and agents through commands.
//    - Enable configuration options for sorting/searching preferences and view log/report options interactively.

// ### 11. **Add Efficiency Tracking**
//    - Integrate timers to measure and display the time complexity for operations, such as ticket management, 
//         agent assignments, and log access.
//    - Optimize functions by minimizing nested loops and other performance bottlenecks.

// ### 12. **Testing and Debugging**
//    - Thoroughly test each component individually (unit testing), 
//         then perform integration testing to ensure all parts work seamlessly together.
//    - Test different scenarios, like high ticket volumes and maximum agent loads, to check system stability.

// ### 13. **Documentation and Finalization**
//    - Write clear documentation to describe each function and class.
//    - Ensure the configuration file, project structure, and code comments (if needed) are well-organized.
