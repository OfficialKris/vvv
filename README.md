# VVV (Virtual Volumes View)
> [!IMPORTANT]
> This is a GIT mirror of the SVN repo:
https://sourceforge.net/projects/vvvapp/

Catalog the content of removable volumes like CD and DVD disks for off-line searching. Folders and files can also be arranged in a single, virtual file system. Each folder of this virtual file system can contain files from many disks. Supports storing audio metadata from most audio fomrats.


It is possible to share the same catalog, stored in a network server, among Windows, Linux and OSX computers. The network server is simply a computer running a database server program.

## Installation
Required dependencies:
- [wxWidgets](https://wxwidgets.org/) (v3.x)
- [taglib](https://taglib.org/) (v2.x)

Installation steps:
```
mkdir build && cd build
cmake ../
make -j8
make install
vvv
```

## Features

VVV is available for Windows, Linux and for OS X (Intel only). You can exchange catalogs between Windows, Linux and OS X computers, and you can connect Windows, Linux and OS X computers to the same (Windows,  Linux or OS X) server.

VVV is very fast, even with very large catalogs. Data is stored in a relational database, designed to handle millions of rows, so retrieving your information will always be a quick task.

VVV can show the content of your disks in three different views:

- Physical View: This view shows the content of each disk as they are in each and every folder.

- Virtual View: In this view everything is organized as a single virtual file system. You can create folders and you can assign physical volumes or folders to each virtual folder. You can assign the same file to more than one virtual folder, and each virtual folder can contain files that are stored in different disks. The virtual view is a powerful tool that will let you organize your data in a logical way: it will save you a lot of searches.

- Search View: In this view you can search the catalog looking for files that meet your specification.

---

<div align=center>
Copyright (C) 2007-2024 The VVV Team
</div>