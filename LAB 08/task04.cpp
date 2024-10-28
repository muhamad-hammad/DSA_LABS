// Q4: Given a Tree of nodes (Down below):
        //         10
        //        / \
        //      5    11
        //     / \
        //    4   7
        //         \
        //          8   
// You are tasked to take a value X from the user and ask whether to ceil or floor the value. If ceil
// is selected find the closest value to X in our case 7 at level three right child because if we ceil 6
// we get 7 (Yes, I am familiar with the logic of how ceil and floor works with floating points but
// this scenario is different so in the case of ceil add 1 to X and in the case of floor subtract 1 from
// x then find the value). Also find multiple occurrences if it as well.