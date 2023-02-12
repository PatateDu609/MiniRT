# Scene description

Each scene is described as a single `.rt` file.

## File Syntax

Each line represents a single object or a single metadata. The following table represents all possible identifiers. Uppercase identifiers represents metdata and can be present only once in a valid file, while lowercase represents objets.

Lines can be commented using `#`

| Identifier | Description                                               |
| ---------- | --------------------------------------------------------- |
| R          | The frame size                                            |
| A          | Ambient lighting, it is implemented using the phong model |
| F          | Filter                                                    |
| c          | Camera                                                    |
| l          | Light                                                     |
| tr         | Triangle                                                  |
| pl         | Plane                                                     |
| sp         | Sphere                                                    |
| sq         | Square                                                    |
| cy         | Cylinder                                                  |
| ci         | Circle                                                    |
| el         | Ellipsoid                                                 |

A valid file is composed by at least a Frame size object, an Ambient light declaration and a Camera.

## Objects syntax

### Frame size

| Argument | Type             |
| -------- | ---------------- |
| Width    | **Unsigned int** |
| Height   | **Unsigned int** |

### Ambient light

| Argument  | Type                                   |
| --------- | -------------------------------------- |
| Intensity | **Double** between 0 and 1             |
| Color     | Color (3 **unsigned char** components) |

### Filter

It takes only one mandatory argument that is the filter type. It may be **none**, **sepia**, **grayscale** and it defaults to **none** if absent.

### Camera

| Argument         | Type                                     |
| ---------------- | ---------------------------------------- |
| Position         | Non-normalized vector read as **double** |
| Vector direction | Normalized vector read as **double**     |
| FOV              | Degrees read as **double**               |

### Light

| Argument  | Type                                     |
| --------- | ---------------------------------------- |
| Position  | Non-normalized vector read as **double** |
| Intensity | **Double** between 0 and 1               |
| Color     | Color (3 **unsigned char** components)   |

### Triangle

| Argument | Type                                     |
| -------- | ---------------------------------------- |
| Vertex 1 | Non-normalized vector read as **double** |
| Vertex 2 | Non-normalized vector read as **double** |
| Vertex 3 | Non-normalized vector read as **double** |
| Color    | Color (3 **unsigned char** components)   |

### Plane

| Argument    | Type                                     |
| ----------- | ---------------------------------------- |
| Point       | Non-normalized vector read as **double** |
| Orientation | Normalized vector read as **double**     |
| Color       | Color (3 **unsigned char** components)   |

### Sphere

| Argument           | Type                                     | Mandatory                                   |
| ------------------ | ---------------------------------------- | ------------------------------------------- |
| Origin             | Non-normalized vector read as **double** | yes                                         |
| Diameter           | **Double**                               | yes                                         |
| Color              | Color (3 **unsigned char** components)   | yes                                         |
| Specular intensity | **double**                               | no                                          |
| Specular color     | Color (3 **unsigned char** components)   | no (yes if specular intensity is specified) |

### Square

| Argument                            | Type                                     |
| ----------------------------------- | ---------------------------------------- |
| Point                               | Non-normalized vector read as **double** |
| Vector director to define the plane | Normalized vector read as **double**     |
| Size                                | **Double**                               |
| Color                               | Color (3 **unsigned char** components)   |

### Cylinder

| Argument    | Type                                                           | Mandatory |
| ----------- | -------------------------------------------------------------- | --------- |
| Base center | Non-normalized vector read as **double**                       | yes       |
| Orientation | Normalized vector read as **double**                           | yes       |
| Color       | Color (3 **unsigned char** components)                         | yes       |
| Diameter    | **Double**                                                     | yes       |
| Height      | **Double**                                                     | yes       |
| -           | **caps** can be added as is to add caps to the cylinder render | no        |

### Circle

| Argument    | Type                                     | Mandatory |
| ----------- | ---------------------------------------- | --------- |
| Base center | Non-normalized vector read as **double** | yes       |
| Normal      | Normalized vector read as **double**     | yes       |
| Color       | Color (3 **unsigned char** components)   | yes       |
| Diameter    | **Double**                               | yes       |

### Ellipsoid

| Argument         | Type                                     |
| ---------------- | ---------------------------------------- |
| Origin           | Non-normalized vector read as **double** |
| Diameter &alpha; | **Double**                               |
| Diameter &beta; | **Double**                               |
| Diameter &gamma; | **Double**                               |
| Color            | Color (3 **unsigned char** components)   |
