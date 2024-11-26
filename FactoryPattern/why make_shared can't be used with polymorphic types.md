The primary reason you cannot use `std::make_shared` directly in the `create_wall` function when creating a shared pointer to the base class `Wall` is because `std::make_shared` does not allow implicit conversions between types. Specifically:

### 1. **Ownership Semantics with `std::make_shared`**
- `std::make_shared` creates a shared pointer that directly owns the object it constructs. This means the type of the object it constructs and the type of the `std::shared_ptr` it creates must be the same.
- In your case, `SolidWall` is derived from `Wall`, and when calling `std::make_shared<SolidWall>()`, it constructs an object of type `SolidWall`. However, the `create_wall` function returns a `std::shared_ptr<Wall>`, requiring a conversion from `std::shared_ptr<SolidWall>` to `std::shared_ptr<Wall>`.
- This conversion is not supported directly by `std::make_shared` because it returns a `std::shared_ptr` tightly bound to the type of the object it allocates.

### 2. **Type Erasure with `std::shared_ptr`
- You can create the `std::shared_ptr` with `new SolidWall` because the `std::shared_ptr` constructor accepts a raw pointer of a derived type and erases the type to the base class. For example:

  ```cpp
  return std::shared_ptr<Wall>(new SolidWall(...));
  ```

- This works because the `std::shared_ptr` explicitly manages the lifetime of the raw pointer and can correctly handle the polymorphic behavior.

### 3. **Avoiding Object Slicing**
- If you use `std::make_shared<Wall>()` instead, it constructs an object of type `Wall` rather than `SolidWall`, which leads to slicing (losing the derived class-specific information). In other words, the constructed object would not include `SolidWall`'s members or behavior.

### Why Doesn't `std::make_shared` Provide an Implicit Conversion?

The lack of implicit conversion in `std::make_shared` is by design. Implicit conversions could lead to subtle bugs:

- **Memory Overhead**: `std::make_shared` allocates memory for the control block and the object in a single memory allocation. Allowing implicit conversions might lead to misaligned expectations of ownership or construction.
- **Safety and Simplicity**: Explicitly using the `std::shared_ptr` constructor for base class conversions ensures that you are aware of the type erasure occurring.

### How to Resolve This

If you need to use `std::make_shared`, you can work around this limitation using a helper function or explicitly converting:

1. **Explicit Conversion Using `std::static_pointer_cast`**
   You can first create the `std::shared_ptr<SolidWall>` and then convert it to `std::shared_ptr<Wall>` using `std::static_pointer_cast`:

   ```cpp
   case WallType::main:
       return std::static_pointer_cast<Wall>(std::make_shared<SolidWall>(start, end, elevation, height, 20, Material::aerated_concrete));
   ```

2. **Using `std::shared_ptr` Constructor**
   Use the `new` keyword to allocate the derived object and create the `std::shared_ptr` directly:

   ```cpp
   case WallType::main:
       return std::shared_ptr<Wall>(new SolidWall(start, end, elevation, height, 20, Material::aerated_concrete));
   ```

3. **Factory Helper**
   To maintain readability, a factory helper function might create `SolidWall` instances and return them as `std::shared_ptr<Wall>`.

The second option is most commonly seen in factory patterns because it is concise and avoids unnecessary complexity with `std::make_shared` when dealing with polymorphic types.