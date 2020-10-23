# LESAPlugin
# LESAPlugin

## Build Dependencies
* [CommonLibSSE](https://github.com/Ryan-rsm-McKenzie/CommonLibSSE)

## End User Dependencies
* [SKSE64](https://skse.silverlock.org/)
* [Address Library for SKSE Plugins](https://www.nexusmods.com/skyrimspecialedition/mods/32444)

--------------------

SKSE64 Plugin Building Requirements
--------------------
### CommonLibSSE (Linked as a submodule)
https://github.com/Ryan-rsm-McKenzie/CommonLibSSE

### vcpkg (For installing packages required by CommonLibSSE)
https://github.com/microsoft/vcpkg

#### Required Packages
After installing vcpkg using the instruction given https://github.com/microsoft/vcpkg, you will need to install the required packages for `CommonLibSSE`, e.g.
  ```
  .\vcpkg install span-lite:x64-windows-static-md
  .\vcpkg install xbyak:x64-windows-static-md
  .\vcpkg install spdlog:x64-windows-static-md
  ```
> NOTE: The above instructions install the current depencies for CommonLibSSE they are subject to change, refer to the site.
> Depending on the revision of CommonLibSSE, you may need to update your copy of the vcpkg triplet used.  To do this:
```
1. Go to properties->Vcpkg->triplet
2. Change '$(VcpkgUserTriplet)-custom' to $(VcpkgUserTriplet)-static-md
```

### Visual Studio 2019
https://visualstudio.microsoft.com/vs/

Building Instructions
--------------------
- Once all the depencencies are sorted out you will need to create the following environmental variables
  > - Skyrim64Path = `<skyrim root>`, The Root folder of the Skyrim Installation where SkyrimSE.exe is located
- Open the solution file `LESAPlugin.sln` in Visual Studio 2019


Disclaimer
----------
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

Thanks to MIT license for providing this standard disclaimer.

Thanks to Bethesda Game Studios for creating The Elder Scrolls V: Skyrim, providing the base content and allowing us to mod it.

Thanks to [Ryan](https://github.com/Ryan-rsm-McKenzie) for making the [CommonLibSSE](https://github.com/Ryan-rsm-McKenzie/CommonLibSSE)
