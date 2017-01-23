using System.ServiceModel;
using System.ServiceModel.Web;

namespace Efficio.Net.Web
{
    // NOTE: You can use the "Rename" command on the "Refactor" menu to change the interface name "IService1" in both code and config file together.
    [ServiceContract]
    public interface IEFficioService
    {


        [OperationContract]
        [WebGet(BodyStyle = WebMessageBodyStyle.Bare, ResponseFormat = WebMessageFormat.Json)]
        Frame GetFrame();
    }
}
