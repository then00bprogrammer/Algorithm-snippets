  int c = tree.lca(a, b);
    cout << "The LCA of " << a << " and " << b << " is " << c << endl; // should output "The LCA of 3 and 4 is 1"

    a = 3, b = 5;
    c = tree.lca(a, b);
    cout << "The LCA of " << a << " and " << b << " is " << c << endl; // should output "The LCA of 3 and 5 is 0"

    a = 4, b = 5;
    c = tree.lca(a, b);
    cout << "The LCA of " << a << " and " << b << " is " << c << endl; // should output "The LCA of 4 and 5 is 0"