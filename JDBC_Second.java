import com.sun.org.apache.xpath.internal.operations.Or;
import dao.CustomerDAO;
import dao.OrderDAO;
import dao.OrderItemDAO;
import model.Customer;
import model.Order;
import model.OrderItem;
import org.postgresql.ds.PGPoolingDataSource;
import javax.sql.DataSource;
import java.sql.SQLException;
import java.util.List;

public class JDBC_Second {
    public static DataSource createDataSource() {
    PGPoolingDataSource poolingDataSource = new PGPoolingDataSource();
    poolingDataSource.setDataSourceName("Lab 2 data source");

    poolingDataSource.setServerName("localhost");
    poolingDataSource.setDatabaseName("Ex");
    poolingDataSource.setUser("postgres");
//    poolingDataSource.setPassword("rtif13");
    poolingDataSource.setPassword("1");
    poolingDataSource.setMaxConnections(8);
    poolingDataSource.setInitialConnections(1);
    return poolingDataSource;
}

    public static void main( String[] args ) throws SQLException {

        DataSource dataSource = createDataSource();

        CustomerDAO customerDAO = new CustomerDAO(dataSource);
        OrderItemDAO orderItemDAO = new OrderItemDAO(dataSource);
        OrderDAO orderDAO = new OrderDAO(dataSource);

        System.out.println("= = = = = Customers list = = = = = =");
        List<Customer> customer = customerDAO.list();
        for (Customer customers : customer) {
            System.out.println(String.format("%s %s (id: %03d) %s %s %s",
                    customers.getLastName(), customers.getFirstName(), customers.getId(),
                    customers.getCity(), customers.getCountry(), customers.getPhone()));
        }

        System.out.println("= = = = = OrderItems list = = = = = =");
        List<OrderItem> orderItem = orderItemDAO.list();
        for (OrderItem orderItems : orderItem) {

            System.out.println(
                    String.format("(orderitem_id: %03d) (order_id: %03d) (product_id: %03d) %d %d",
                            orderItems.getId(), orderItems.getOrderId(),
                            orderItems.getProductId(), orderItems.getUnitPrice(),
                            orderItems.getQuantity()
                    )
            );
        }

        System.out.println("= = = = = Order list = = = = = =");
        List<Order> orders = orderDAO.list();
        for (Order order: orders){
            System.out.println(
                    String.format("(order_id: %03d) %s (customer_id: %03d) %d %s",
                            order.getId(), order.getOrderDate(),
                            order.getCustomerId(), order.getTotalAmount(),
                            order.getOrderNumber())
            );
        }

        customerDAO.delete(19,4);
        customerDAO.insert(4,"John","Enriot","Eims","France","26.47.15.10");
        orderDAO.insert(19, "October  2 2017 11:00:00:000PM", 4, 1191, "542449");
        orderItemDAO.insert(24,19,14,10,15);

        System.out.println("= = = = = Final Order list = = = = = =");
        List<Order> ordersFL = orderDAO.list();
        for (Order order: ordersFL){
            System.out.println(
                    String.format("(order_id: %03d) %s (customer_id: %03d) %d %s",
                            order.getId(), order.getOrderDate(),
                            order.getCustomerId(), order.getTotalAmount(),
                            order.getOrderNumber())
            );
        }

        System.out.println("= = = = = Final OrderItems list = = = = = =");
        List<OrderItem> orderItemFL = orderItemDAO.list();
        for (OrderItem orderItems : orderItemFL) {

            System.out.println(
                    String.format("(orderitem_id: %03d) (order_id: %03d) (product_id: %03d) %d %d",
                            orderItems.getId(), orderItems.getOrderId(),
                            orderItems.getProductId(), orderItems.getUnitPrice(),
                            orderItems.getQuantity()
                    )
            );
        }

        System.out.println("= = = = = Final Customers list = = = = = =");
        List<Customer> customerFL = customerDAO.list();
        for (Customer customers : customerFL) {
            System.out.println(String.format("%s %s (id: %03d) %s %s %s",
                    customers.getLastName(), customers.getFirstName(), customers.getId(),
                    customers.getCity(), customers.getCountry(), customers.getPhone()));
        }

        customerDAO.update(1, "Jong", "Van", "Bern", "Switzerland", "0452-076545");

        System.out.println("= = = = = Updated Customers list = = = = = =");
        List<Customer> customerSL = customerDAO.list();
        for (Customer customers : customerSL) {
            System.out.println(String.format("%s %s (id: %03d) %s %s %s %s",
                    customers.getLastName(), customers.getFirstName(), customers.getId(),
                    customers.getCity(), customers.getCountry(), customers.getPhone(), customers.getDateOfChange()));
        }

    }
}
